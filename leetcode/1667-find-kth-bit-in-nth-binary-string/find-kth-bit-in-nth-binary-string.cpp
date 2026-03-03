class Solution {
public:
    string bulltin_discount(string present){
        for(auto &i : present){
            if(i == '1') i = '0';
            else i = '1';
        }
        if(present.size() > 1)
        reverse(present.begin(),present.end());

        return present;
    }
    string level(string cur,int depth,int n){
        if(depth == n){
            return cur;
        }
        string latest = cur + "1" + bulltin_discount(cur);
        return level(latest,depth+1,n);
    }
    char findKthBit(int n, int k) {
        string begin = "0";
        string NOW = level(begin,1,n);
        // cout << NOW << endl;
        return NOW[k - 1];
    }
};