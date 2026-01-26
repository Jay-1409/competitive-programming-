class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        map<int,vector<vector<int>>> mp;
        int gap = INT_MAX;
        for(int i = 0; i < arr.size() - 1; ++i) {
            mp[arr[i + 1] - arr[i]].push_back({arr[i], arr[i + 1]});
            gap = min(gap, arr[i + 1] - arr[i]);
        }
        return mp[gap];
    }
};