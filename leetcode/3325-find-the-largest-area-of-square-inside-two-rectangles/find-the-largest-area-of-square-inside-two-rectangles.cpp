class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        auto does_intersect = [&](vector<int> &a, vector<int> &a_, vector<int> &b, vector<int> &b_) -> bool {
            if(a[1] >= b_[1])
                return false;
            if(a_[0] <= b[0])
                return false;
            if(a_[1] <= b[1])
                return false;
            if(b_[0] <= a[0])
                return false;
            return true;
        };
        auto get_area = [&](vector<int> &a, vector<int> &a_, vector<int> &b, vector<int> &b_) -> long long {
            long long x_overlap = max(0, min(a_[0], b_[0]) - max(a[0], b[0]));
            long long y_overlap = max(0, min(a_[1], b_[1]) - max(a[1], b[1]));
            return min(x_overlap, y_overlap) * min(x_overlap, y_overlap);
        };
        long long ans = 0;
        int n = bottomLeft.size();
        for(int i = 0 ;i < n; ++i) {
            for(int j = 0; j < i; ++j) {
                if(does_intersect(bottomLeft[i], topRight[i], bottomLeft[j], topRight[j])) {
                    ans = max(ans,get_area(bottomLeft[i], topRight[i], bottomLeft[j], topRight[j]));
                }
            }
        }
        return ans;
    }
};