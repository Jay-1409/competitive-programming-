class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        auto f = [](const string &code) -> bool {
            if (code.empty()) 
                return false;
            for (char i : code) {
                if (!isalnum(i) && i != '_') 
                    return false;
            }
            return true;
        };
        auto g = [&](const string &line) -> bool {
            if(line == "electronics" || line == "grocery" || line == "pharmacy" || line == "restaurant")
                return true;
            return false;
        };
        vector<pair<string,string>> p;
        int n = code.size();
        for(int i = 0 ; i < n; i++) {
            if(isActive[i]) {
                if(f(code[i]) && g(businessLine[i])){
                    p.push_back({code[i], businessLine[i]});
                }
            }
        }
        sort(p.begin(), p.end(), [&](const pair<string,string> &a, const pair<string,string>&b){
        if (a.second == "electronics") {
                if (b.second == "electronics") {
                    return a.first < b.first;
                }
                return true;
            }
            if (a.second == "grocery") {
                if (b.second == "electronics") {
                    return false;
                }
                if (b.second == "grocery") {
                    return a.first < b.first;
                }
                return true;
            }
            if (a.second == "pharmacy") {
                if (b.second == "electronics" || b.second == "grocery") {
                    return false;
                }
                if (b.second == "pharmacy") {
                    return a.first < b.first;
                }
                return true;
            }
            if (a.second == "restaurant") {
                if (b.second == "restaurant") {
                    return a.first < b.first;
                }
                return false;
            }
            if (b.second == "electronics" || b.second == "grocery" || b.second == "pharmacy" || b.second == "restaurant") {
                return false;
            }
    return a.first < b.first;
        });
        vector<string> s;
        for(auto &i : p){
            s.push_back(i.first);
        }
        return s;
    }
};