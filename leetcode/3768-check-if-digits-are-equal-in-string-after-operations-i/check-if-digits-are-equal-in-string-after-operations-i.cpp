class Solution {
public:
    bool hasSameDigits(string s) {
        vector<int> a;
        while(true) {
            vector<int> v;
            for(int i = 0; i < (int)s.size() - 1; ++i) {
                int a = s[i] - '0';
                int b = s[i + 1] - '0';
                int c = (a + b) % 10;
                v.push_back(c); 
            }
            a = v;
            if((int)a.size() == 2)
                break;
            string x;
            for(auto &I : v) {
                x.push_back('0'+ I);
            }
            s = x;
        }
        return a[(int)a.size() - 1] == a[(int)a.size() - 2];
    }
};