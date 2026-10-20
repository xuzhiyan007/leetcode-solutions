import { LeetCodeCN } from "leetcode-query";
import { execSync } from "node:child_process";
import { mkdirSync, writeFileSync } from "node:fs";
import path from "node:path";

// 语言 -> 文件扩展名
const EXT = {
    cpp: "cpp", java: "java", python: "py", python3: "py", c: "c", csharp: "cs",
    javascript: "js", typescript: "ts", golang: "go", ruby: "rb", swift: "swift",
    scala: "scala", kotlin: "kt", rust: "rs", mysql: "sql", php: "php",
    bash: "sh", pandas: "py", postgres: "sql", oraclesql: "sql", pythondata: "py",
};

const GIT_NAME = process.env.GIT_NAME || "unknown";
const GIT_EMAIL = process.env.GIT_EMAIL || "unknown@unknown";
const FOLDER = "solutions";

const sh = (cmd, env = {}) =>
    execSync(cmd, { encoding: "utf8", env: { ...process.env, ...env } }).trim();

// 与 leetcode-query 内置的 credential-cn 相同的 csrf 获取逻辑
async function get_csrf() {
    const res = await fetch("https://leetcode.cn/graphql/", {
        method: "POST",
        headers: { "content-type": "application/json" },
        body: JSON.stringify({
            operationName: "nojGlobalData",
            variables: {},
            query: "query nojGlobalData {\n  siteRegion\n  chinaHost\n  websocketUrl\n}\n",
        }),
    });
    const m = (res.headers.get("set-cookie") || "").match(/csrftoken=([^;]+)/);
    return m ? m[1] : "";
}

const session = process.env.LEETCODE_SESSION;
if (!session) {
    console.error("ERROR: LEETCODE_SESSION secret is missing");
    process.exit(1);
}

// 登录并校验 cookie 有效性
const lc = new LeetCodeCN({ session, csrf: await get_csrf() });
const st = await lc.userStatus();
if (!st?.isSignedIn) {
    console.error("ERROR: LeetCode session expired — update the LEETCODE_SESSION secret");
    process.exit(1);
}
console.log("signed in as:", st.userSlug || st.username || "ok");

// —— 诊断：写出原始响应，便于远程排查 ——
const probes = {
    solved: await lc.user_progress_questions({ skip: 0, limit: 5, questionStatus: "SOLVED" }).catch((e) => String(e)),
    all: await lc.user_progress_questions({ skip: 0, limit: 5 }).catch((e) => String(e)),
};
writeFileSync("debug.json", JSON.stringify(probes, null, 2));
sh(`git add debug.json && git commit -m "debug: userProgressQuestionList probe"`);

// 拉取全部"已解决"题目（分页）
const solved = [];
let skip = 0;
for (;;) {
    const data = await lc.user_progress_questions({
        skip,
        limit: 100,
        questionStatus: "SOLVED",
    });
    const upl = data?.userProgressQuestionList;
    if (!upl) break;
    solved.push(...upl.questions);
    skip += 100;
    if (!upl.questions.length || solved.length >= upl.totalNum) break;
}
console.log("total solved:", solved.length);

// 幂等：已存在的题目跳过
const existing = new Set(sh(`git ls-files ${FOLDER}`).split("\n").filter(Boolean));
mkdirSync(FOLDER, { recursive: true });

let added = 0;
for (const q of solved) {
    const stem = `${q.frontendId ? q.frontendId + "." : ""}${q.titleSlug}`;
    if ([...existing].some((f) => f.startsWith(stem + "."))) continue;

    // 取该题最早的通过记录作为 commit 时间
    const subs = await lc.problem_submissions({ slug: q.titleSlug, limit: 1000 });
    const ac = subs
        .filter((s) => s.statusDisplay === "Accepted")
        .sort((a, b) => a.timestamp - b.timestamp)[0];
    if (!ac) {
        console.log("no AC submission found:", stem);
        continue;
    }

    const detail = await lc.submissionDetail(String(ac.id));
    const code = detail?.code ?? "";
    if (!code.trim()) {
        console.log("empty code, skip:", stem);
        continue;
    }
    const lang = (detail?.lang || ac.lang || "txt").toLowerCase();
    const ext = EXT[lang] || lang || "txt";

    const file = path.join(FOLDER, `${stem}.${ext}`);
    writeFileSync(file, code.endsWith("\n") ? code : code + "\n");

    const date = new Date(ac.timestamp).toISOString();
    const msg = `solve ${stem} (${(q.difficulty || "?").toLowerCase()}, ${lang})`;
    sh(`git add ${JSON.stringify(file)}`);
    sh(`git commit -m ${JSON.stringify(msg)}`, {
        GIT_AUTHOR_NAME: GIT_NAME,
        GIT_AUTHOR_EMAIL: GIT_EMAIL,
        GIT_AUTHOR_DATE: date,
        GIT_COMMITTER_NAME: GIT_NAME,
        GIT_COMMITTER_EMAIL: GIT_EMAIL,
        GIT_COMMITTER_DATE: date,
    });
    existing.add(file);
    added++;
    console.log("+", file, date);
}

console.log(`done: committed ${added} new solution(s)`);
