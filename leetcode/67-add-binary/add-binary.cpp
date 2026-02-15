class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int p = 0;
        int carr = 0;
        while(p < (int)a.size() || p < (int)b.size()) {
            int x, y;
            if(p >= (int)a.size()) 
                x = 0;
            else
                x = a[p] - '0';
            if(p >= (int)b.size()) 
                y = 0;
            else
                y = b[p] - '0';
            int next = 0;
            int curr = 0;
            if(x + y + carr == 3) {
                carr = 1;
                curr = 1;
            } else if(x + y + carr == 2) {
                carr = 1;
                curr = 0;
            } else if(x + y + carr == 1) {
                curr = 1;
                carr = 0;
            } else {
                curr = 0;
                carr = 0;
            }
            ans.push_back(curr + '0');
            p++;
        }
        if(carr) 
            ans.push_back(carr + '0');
        reverse(ans.begin(), ans.end());
        return ans;
    }
};