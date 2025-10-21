class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        const long long MOD = 1e9 + 7;
        long long normal_sum = accumulate(arr.begin(), arr.end(), 0);
        long long kadanes_sum = 0;
        long long cursum = 0;
        for(int i = 0; i < (int)arr.size(); ++i) {
            cursum = max(cursum + arr[i], (long long)arr[i]);
            kadanes_sum = max(kadanes_sum, cursum);
        }
        if(k == 1)
            return kadanes_sum;
        long long partial_sum = normal_sum * (k);
        long long left_removable_sum = 0, right_removable_sum = 0;
        long long negative = 0;
        long long positive = 0;
        for(int i = 0; i < (int)arr.size(); ++i) {
            if(arr[i] < 0) {
                negative += arr[i];
            } else {
                positive += arr[i];
            }
            if(negative + positive < 0) {
                left_removable_sum = min((negative + positive), left_removable_sum);
            }
        }     
        negative = 0; 
        positive = 0;
        for(int i = (int)arr.size() - 1; i >= 0; --i) {
            if(arr[i] < 0) {
                negative += arr[i];
            } else {
                positive += arr[i];
            }
            if(negative + positive < 0) {
                right_removable_sum = min((negative + positive), right_removable_sum);
            }
        }
        cout << (right_removable_sum + left_removable_sum) << endl;
        long long half_sum = 2 * normal_sum - (right_removable_sum + left_removable_sum);
        long long ans = max({kadanes_sum, partial_sum - (right_removable_sum + left_removable_sum), half_sum});
        return max(0LL, ans % MOD);
    }
};

// NOTES
            // we can repeat all the steps to get some or the other sum 
            // now we will have the option to remove sum prefix and some suffix from the entire array 
            // this enables us to remove the negative elements that lie in the suffix and the negative elements that lie in the prefix 
            // but be careful we cannot just reove them like that we need to make sure that the net change is in our favour 

            // that is the positive - negative < 0 