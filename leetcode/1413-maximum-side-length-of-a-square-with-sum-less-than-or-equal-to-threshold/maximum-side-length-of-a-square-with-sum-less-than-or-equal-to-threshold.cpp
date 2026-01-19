class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        // prefix sum on 2d matrix 
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> pfx(n, vector<int>(m));
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                pfx[i][j] = mat[i][j];
                if(i > 0) 
                    pfx[i][j] += pfx[i - 1][j];
                if(j > 0)
                    pfx[i][j] += pfx[i][j - 1];
                if (i > 0 && j > 0) 
                    pfx[i][j] -= pfx[i - 1][j - 1];
            }
        }
        int len = 0;
        for(int i = 0 ;i < n; ++i ) {
            for(int j = 0; j < m; ++j) {
                for(int k = 0; i + k < n && j + k < m; ++k) {
                    int sum = pfx[i + k][j + k];
                    if (i > 0)
                        sum -= pfx[i - 1][j + k];
                    if (j > 0)
                        sum -= pfx[i + k][j - 1];
                    if (i > 0 && j > 0)
                        sum += pfx[i - 1][j - 1];
                    if(sum <= threshold)
                        len = max(len, k + 1);
                }
            }
        }
        return len;
    }
};