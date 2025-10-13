class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        //sliding window to keep number of distinct values in a segment <= 2 
        // that is it ig 
        map<int,int> mp;
        set<int> st;
        int l = 0;
        int sum = 0;
        int maxsum = 0;
        for(int r = 0; r < (int)fruits.size(); ++r) {
            // cout << fruits[r] << " " << st.size() << endl;
            st.insert(fruits[r]);
            while(st.size() > 2) {
                // cout <<"more than 2 distinct" << endl;
                mp[fruits[l]]--;
                if(mp[fruits[l]] == 0) {
                    st.erase(fruits[l]);
            //   cout << "erasing " << fruits[l] << " at " << l << " " << st.size() << endl;
                }
                sum -= fruits[l];
                l++;
            }
            mp[fruits[r]]++;
            maxsum = max(maxsum, r - l + 1);
        }
        return maxsum;
    }
};