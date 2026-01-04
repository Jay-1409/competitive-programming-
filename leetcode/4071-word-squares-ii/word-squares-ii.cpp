class Solution {
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        vector<string> sorivandek = words; // required

        set<vector<string>> st;
        int n = words.size();

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) 
                if (j != i) {
                for (int k = 0; k < n; ++k) 
                    if (k != i && k != j) {
                    for (int l = 0; l < n; ++l) 
                        if (l != i && l != j && l != k) {
                        string &top = words[i];
                        string &left = words[j];
                        string &right = words[k];
                        string &bottom = words[l];
                        if (top[0] == left[0] && top[3] == right[0] && bottom[0] == left[3] && bottom[3] == right[3]) {
                            st.insert({top, left, right, bottom});
                        }
                    }
                }
            }
        }

        return vector<vector<string>>(st.begin(), st.end());
    }
};
