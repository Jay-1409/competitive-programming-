class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n = mat.size(); int m = mat[0].size();
        vector<vector<int>> nmat(n, vector<int>(m));
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                nmat[i][j] = mat[i][(((i & 1) ? j + k : j - k) % m + m) % m];     
           }
        }
        return nmat == mat;
    }
};