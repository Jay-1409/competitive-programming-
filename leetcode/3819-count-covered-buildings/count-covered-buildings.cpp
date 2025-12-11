class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        vector<int> row_min(n+1, INT_MAX), row_max(n+1, INT_MIN);
        vector<int> col_min(n+1, INT_MAX), col_max(n+1, INT_MIN);
        for (auto &b : buildings) {
            int x = b[0];   
            int y = b[1];   
            row_min[x] = min(row_min[x], y);
            row_max[x] = max(row_max[x], y);
            col_min[y] = min(col_min[y], x);
            col_max[y] = max(col_max[y], x);
        }
        int count = 0;
        for (auto &b : buildings) {
            int x = b[0];
            int y = b[1];
            if (y > row_min[x] && y < row_max[x] && x > col_min[y] && x < col_max[y]) {
                count++;
            }

        }
        return count;
    }
};
