class Solution:
    def matrixReshape(self, mat: List[List[int]], r: int, c: int) -> List[List[int]]:
        b=[];d=[]
        for i in range(len(mat)):
            for j in mat[i]:
                b.append(j)
        m=len(mat);n=len(mat[0])

        if m*n != r*c:
            return mat
        if m*n == r*c:
            for i in range(r):
                a=list((b[i*c:(i+1)*c]))
                d.append(a)
            return d
