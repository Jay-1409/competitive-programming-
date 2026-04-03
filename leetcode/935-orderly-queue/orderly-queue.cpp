class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k > 1) {
            sort(s.begin(), s.end());
            return s;
        }
        if(s.size() == 1) {
            return s;
        }
        int n = s.size();
        string ans = s;
        while(n--) {
            rotate(s.begin(), s.begin() + 1, s.end());
            ans = min(ans, s);
        }
        return ans;
    }
};

/** NOTES   
    choose one of the first.k and move that character to the back !
    if(k == 1)
        just try to get a[0] < a[1]; is possible
         bca -> ans in this casse
         cab -> acb better ans, fallacy

         insteaed just brute force!!

    if k == n -> i can essentially sort the entire array!! -> yes

    with k < n -> if i detect a[i] > a[i + 1] where i < k then i can that ith element to the back! 
    

    is aabaaaacaa smaller or aaaaaaacaab smaller? ->. aaaaaaacaab
    aaababaa -> can cause infinit loop!! -> is it essentially normal sort?


**/