class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        vector<int> copy_nums = nums;
        sort(copy_nums.begin(), copy_nums.end());
        auto check = [&](int k) -> bool {
            multiset<int> cur, req;
            unordered_map<int,int> freq;
            vector<int>cur2;
            int exp_val = 0;
            int down = 0;
            for(int i = 0; i < n; ++i) {
                if(!cur2.empty() && cur2.back() > nums[i]) {
                    down++;
                    if(down >= 2)
                        return false;
                }
                freq[nums[i]]++;
                freq[copy_nums[exp_val++]]--;
                // cur.insert(nums[i]);
                cur2.push_back(nums[i]);
                // req.insert(copy_nums[exp_val++]);
                if((i + 1) % k == 0) {
                    if(cur2[k-1] > cur2[0]) 
                            down++;
                    if(down >= 2)
                        return false;
                    down = 0;
                    //end of segment 
                    for(auto &i : freq) {
                        if(i.second != 0)
                                return false;
                    }
                    // if(cur != req) {
                    //     return false;
                    // }
                    cur2.clear();
                    freq.clear();
                }
            }
            return true;
        };
        for(int i = 1; i * i <= n; ++i) {
            if(n % i == 0) {
                int d1 = i;
                int d2 = n / i;
                if(d1 == d2)
                    goto single;
                if(check(d1)) {
                    sum += d1;
                }
                single:;
                if(check(d2)) {
                    sum += d2;
                }
            }
        }
        return sum;
    }
};