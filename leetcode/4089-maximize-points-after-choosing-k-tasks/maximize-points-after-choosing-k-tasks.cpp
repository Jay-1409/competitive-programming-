class Solution {
public:
    long long maxPoints(vector<int>& technique1, vector<int>& technique2, int k) {
        vector<pair<int,int>> losses;
        int n = technique1.size();
        for(int i = 0; i < n; ++i) {
            losses.push_back({technique2[i] - technique1[i], i});
        }
        sort(losses.begin(), losses.end());
        long long sum = 0;
        for(int i = 0; i < k; ++i) {
            sum += technique1[losses[i].second];
        }
        for(int i = k; i < n; ++i) {
            sum += max(technique1[losses[i].second], technique2[losses[i].second]);
        }
        return sum;
    }
};