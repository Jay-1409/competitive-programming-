class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int lo = 0;
        int hi = mat[0].size() - 1;
        while(lo <= hi) {
            int mid = (hi + lo) / 2;
            int col = -1;
            int maxe = 0;
            auto f = [&](int column) -> void {
                for(int i = 0; i < (int)mat.size(); ++i) {
                    if(mat[i][column] > maxe) {
                        maxe = mat[i][column];
                        col = column;
                    }
                }
            };
            auto getCords = [&](int ele, int column) -> int {
                for(int i = 0; i < (int)mat.size(); ++i) {
                    if(mat[i][column] == ele)
                        return i;
                }
                return -1;
            };
            f(mid);
            if(mid > 0) 
                f(mid - 1);
            if(mid + 1 < (int)mat[0].size()) 
                f(mid + 1);
            if(col == mid) {
                /* e.g.
                    * * *
                    * # *
                    * * *
                */
                return {getCords(maxe, mid), mid};
            } else if(col == mid - 1) {
                /* e.g.
                    * * * 
                    # * *
                    * * * 
                */
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return {};
    }
};