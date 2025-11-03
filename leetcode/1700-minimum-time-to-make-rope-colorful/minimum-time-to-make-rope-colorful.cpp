class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        int cnt = 0;
        for(int i = 0; i < n - 1; ++i) {
            int j = i + 1;
            priority_queue<int, vector<int>, greater<int>> pq;
            pq.push(neededTime[i]);
            int len = 0;
            while(colors[i] == colors[j]) {
                pq.push(neededTime[j++]);
                len++;
            }
            while(len--) {
                cnt += pq.top();
                pq.pop();
            }
            if(j > i + 1) {
                i = j - 1;
            }
        }
        return cnt;
    }
};