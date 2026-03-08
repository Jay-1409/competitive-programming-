class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string x;
        int loc = 0;
        for(auto &i : nums) {
            // cout << loc << " " << i << endl;
            x.push_back(i[loc] == '1' ? '0' : '1'); 
            loc++;
        }
        return x;
    }
};