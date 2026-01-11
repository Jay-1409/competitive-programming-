class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int len = 0;
        int ans = 0;
        int m = matrix[0].size();
        int n = matrix.size();
        vector<int> prev(m, 0);
        auto maxArea = [&]() -> int {
            stack<int> stk;
            vector<int> next(m, m), _prev(m, -1);
            int loc = 0;
            for(auto &i : prev) {
                while(!stk.empty() && i < prev[stk.top()]) {
                    next[stk.top()] = loc;
                    stk.pop();
                }
                stk.push(loc);
                loc++;
            }
            loc = 0;
            while(!stk.empty()) stk.pop();
            for(int i = m - 1; i >= 0; i--) {
                while(!stk.empty() && prev[stk.top()] > prev[i]) {
                    _prev[stk.top()] = i;
                    stk.pop();
                }
                stk.push(i);
            }
            int sub_ans = 0;
            for(auto &I : prev) {
                int _next = next[loc] - 1;
                int __prev = _prev[loc] + 1;
                // cout << loc << " " << _next << endl;
                sub_ans = max(sub_ans, I * (_next - __prev + 1));
                loc++;
            }
            //cout << "---" << endl;
            return sub_ans;
        };
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(matrix[i][j] == '0') {
                    prev[j] = 0;
                } else
                    prev[j] += (matrix[i][j] - '0');
            }
            ans = max(maxArea(), ans);
        }
        return ans;
    }
};