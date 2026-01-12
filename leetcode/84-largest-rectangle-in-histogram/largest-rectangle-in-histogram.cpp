class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> stk;
        int n = heights.size();
        vector<int> next(n, n), prev(n, -1);
        int loc = 0;
        for(auto &i : heights) {
            while(!stk.empty() && heights[stk.top()] > i) {
                next[stk.top()] = loc;
                stk.pop();
            }
            stk.push(loc++);
        }
        while(!stk.empty())
            stk.pop();
        for(int i = n - 1; i >=0; --i) {
            while(!stk.empty() && heights[stk.top()] > heights[i]) {
                prev[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }
        while(!stk.empty())
            stk.pop();
        int ans = 0;
        for(int i = 0; i < n; ++i) {
            int gap = next[i] - 1 - prev[i];
            ans = max(ans, gap * heights[i]);
            //cout << next[i] << " " << prev[i] << " " << gap << endl;
        }
        return ans;
    }
};