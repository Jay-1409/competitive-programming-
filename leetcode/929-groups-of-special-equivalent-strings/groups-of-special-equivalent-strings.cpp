class Solution {
public:
    int numSpecialEquivGroups(vector<string>& words) {
        map<string, int> mp;
        for(auto &I : words) {
            string od, ev;
            for(int j =0; j < (int)I.size(); ++j) {
                if(j & 1) {
                    od.push_back(I[j]);
                } else
                    ev.push_back(I[j]);
            }
            sort(od.begin(), od.end());
            sort(ev.begin(), ev.end());
            mp[od + ev]++;
        }  
        return (int)mp.size();
    }
};