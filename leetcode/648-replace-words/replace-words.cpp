class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        vector<string> words;
        stringstream s(sentence);
        string word;
        while(s >> word) {
            words.push_back(word);
        }
        set<string> st;
        for(auto &I : dictionary) {
            st.insert(I);
        }
        for(auto &I : words) {
            string pfx;
            for(auto &j : I) {
                pfx.push_back(j);
                if(st.find(pfx) != st.end()) {
                    I = pfx;
                    break;
                }
            }
        }
        string x = "";
        for(int i = 0; i < (int)words.size(); ++i) {
            if(i != (int)words.size() - 1) {
                x += words[i];
                x += " ";
            }
                else
                    x += words[i];
        }
        return x;
    }   
};