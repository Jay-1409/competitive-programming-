class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        auto cleen = [&](string x) -> string {
            int attheraatepos = 0;
            for(int i = 0; i < (int)x.size(); ++i) {
                if(x[i] == '@') {
                    attheraatepos = i;
                    break;
                }
            }
            string f;
            for(int i = 0; i < attheraatepos; ++i) {
                if(x[i] == '+') 
                    break;
                else if(x[i] != '.')
                {
                    f.push_back(x[i]);
                }
            }
            string domain = x.substr(attheraatepos, (int)x.size() - attheraatepos);
            f += domain;
            return f;
        };
        set<string> ans;
        for(auto &i : emails) {
            ans.insert(cleen(i));
        }
        return (int)ans.size();
    }
};