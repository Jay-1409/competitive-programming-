class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> arr(query_row + 2, vector<double>(query_row + 2, 0));
        arr[0][0] = poured;
        arr[1][0] = arr[1][1] = max(0.0, (poured - 1) / 2.0);
        arr[0][0] = min(arr[0][0], 1.0);
        for(int i = 2; i <= query_row + 1; ++i) {
            arr[i][0] = max(0.0, (arr[i - 1][0] - 1) / 2.0);
            arr[i][i] = max(0.0, (arr[i - 1][i - 1] - 1) / 2.0);
            for(int j = 1; j < i; ++j) {
                arr[i][j] = (max(0.0,(arr[i - 1][j] - 1) / 2.0) + max(0.0,(arr[i - 1][j - 1] - 1) / 2.0));
            }
            for(int j = 0; j <= i; ++j) {
                arr[i - 1][j] = min(arr[i - 1][j], 1.0);
            }
        }
        // for(int i = 0; i <= query_row; ++i) {
        //     for(int j = 0; j <= query_row; ++j) {
        //         cout << arr[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        return arr[query_row][query_glass];
    }
};