class Solution {
    multiset<long long> l, r;
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();
        // picking up the first number
        k--;
        long long cur = nums[0];
        // picking up all the valid index considering we take all the index in consecutive order 
        for (int i = 1; i <= dist + 1; i++) cur += nums[i], l.insert(nums[i]);
        // if we get more than k elements then we delete it. But before doing so we keep it in r set (reason is we tend to keep elements in r which we don't use in l)
        while (l.size() > k) {
            cur -= *l.rbegin();
            r.insert(*l.rbegin());
            l.erase(l.find(*l.rbegin()));
        }

        // so we got the min sum of the first dist + 1 elements using sliding window. Now let's slide through the rest of the array

        // ans is the minimum sum of the first element of k subarrays meeting all the conditions
        long long ans = cur;

        // summary: at every index, we try to put it in our l set so that we can get the minimum ans.
        for (int i = dist + 2; i < n; i++) {
            // Erasing an element from the set 
            // i - dist - 1 is the second element. If it will be present in the array then we cannot pick the ith element, so remove it. 
            if (l.find(nums[i - dist - 1]) != l.end()) {
                cur -= nums[i - dist - 1];
                l.erase(l.find(nums[i - dist - 1]));
            } else {
                // if the second element is not present in l set so we have to remove it from r set too. This is done because we don't wanna choose that element in the future of this for loop 
                // because it will destroy the condition of kth index - 1st index is less than or equal to dist if we.
                r.erase(r.find(nums[i - dist - 1]));
            }
            // Adding an element to the set
            // Now we try to add that element that is ith 
            if (nums[i] < *l.rbegin()) {
                cur += nums[i];
                l.insert(nums[i]);
            } else {
                r.insert(nums[i]);
            }
            // Balancing the set such that the first set has (k - 1) elements 
            while (l.size() < k) {
                cur += *r.begin();
                l.insert(*r.begin());
                r.erase(r.find(*r.begin()));
            }
            while (l.size() > k) {
                cur -= *l.rbegin();
                r.insert(*l.rbegin());
                l.erase(l.find(*l.rbegin()));
            }
            // Finally, update the minimum
            ans = min(ans, cur);
        }
        return ans;
    }
};