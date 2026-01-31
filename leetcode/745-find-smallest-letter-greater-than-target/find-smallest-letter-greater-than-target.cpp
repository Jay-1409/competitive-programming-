class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        sort(letters.begin(), letters.end());
        int min_dist = INT_MAX;
        char good_chr = '1';
        int n = letters.size();
        for(int i = 0; i < n; ++i) {
            if((letters[i] > target) && (letters[i] - target < min_dist)) {
                min_dist = (letters[i] - target);
                good_chr = letters[i];
            }
        }
        return (good_chr == '1' ? letters[0] : good_chr);
    }
};