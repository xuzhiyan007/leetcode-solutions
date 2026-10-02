class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        std::vector<vector<int>> vec( cols, vector<int>(rows) );
        for (int i = 0; i < matrix.size(); i++){
            for (int j = 0; j < matrix[i].size(); j++){
                vec[j][i] = matrix[i][j];
            }
        }
        return vec;
    }
};
