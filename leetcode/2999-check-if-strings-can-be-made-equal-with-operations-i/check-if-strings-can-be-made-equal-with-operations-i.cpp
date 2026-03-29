class Solution {
public:
    bool canBeEqual(string _s1, string _s2) {
        set<int> s1, s2, s3, s4;
        for(int i = 0; i < (int)_s1.size(); ++i) {
            if(i & 1) {
                s1.insert(_s1[i]);
                s3.insert(_s2[i]);
            } else {
                s2.insert(_s1[i]);
                s4.insert(_s2[i]);
            }
        }
        return s1 == s3 && s2 == s4;
    }
};