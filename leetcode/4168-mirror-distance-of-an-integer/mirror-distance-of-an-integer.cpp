class Solution {
public:
    int mirrorDistance(int n) {
        string x = to_string(n);
        reverse(x.begin(), x.end());
        int num = stoi(x);
        return abs(num - n);
    }
};