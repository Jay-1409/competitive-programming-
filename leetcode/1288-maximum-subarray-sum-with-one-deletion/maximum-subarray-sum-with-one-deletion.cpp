class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        vector<int> prefix_max(n, 0);
        vector<int> suffix_max(n, 0);
        int curmax = arr[0];
        int overall_max = arr[0];
        prefix_max[0] = arr[0];
        for(int i = 1; i < n; ++i) {
            curmax = max(arr[i], curmax + arr[i]);
            overall_max = max(overall_max, curmax);
            prefix_max[i] = curmax;
        }
        reverse(arr.begin(), arr.end());
        curmax = arr[0];
        overall_max = arr[0];
        suffix_max[0] = arr[0];
        for(int i = 1; i < n; ++i) {
            curmax = max(arr[i], curmax + arr[i]);
            overall_max = max(overall_max, curmax);
            suffix_max[i] = curmax;
        }
        reverse(suffix_max.begin(), suffix_max.end());
        int maxe = max(overall_max, arr[0]);
        for(int i = 1; i < n - 1; i++) {
            int left = prefix_max[i - 1];
            int right = suffix_max[i + 1];
            maxe = max({maxe, left + right, left, right});
        }
        return maxe;
    }
};
/**
- You can delete one element from whatever subarray that you choose
- get the maximum sum including that ith element for all elemetns 
- do this in reverse
- traverse agai and join both the one. 

- get the maximal subarray sum by using kadanes algorithm

**/