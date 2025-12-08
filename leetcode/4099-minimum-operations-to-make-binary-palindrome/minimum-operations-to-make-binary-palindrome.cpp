class Solution {
public:
    vector<int> minOperations(vector<int>& nums) {
        vector<long long> binary_pals;
        auto get_num_from_binary_string = [&](const string &num) -> long long {
            long long val = 0;
            for (int i = 0; i < (int)num.size(); i++) {
                if (num[num.size() - 1 - i] == '1') {
                    val |= (1LL << i);
                }
            }
            return val;
        };
        auto generate_all_binary_palindromes = [&](int loc, string &cur, auto &&self) -> void {
            if (loc == 8) {
                string left = cur;
                int firstOne = left.find('1');
                if (firstOne == string::npos) return;
                left = left.substr(firstOne);
                {
                    string right = left;
                    reverse(right.begin(), right.end());
                    string full = left + right;
                    binary_pals.push_back(get_num_from_binary_string(full));
                }
                if (left.size() == 1) {
                    binary_pals.push_back(1LL);
                }
                if (left.size() > 1) {
                    string base = left.substr(0, left.size() - 1);
                    char mid = left.back();
                    string right = base;
                    reverse(right.begin(), right.end());
                    string full = base + mid + right;
                    binary_pals.push_back(get_num_from_binary_string(full));
                }
                return;
            }
            cur.push_back('0');
            self(loc + 1, cur, self);
            cur.pop_back();
            cur.push_back('1');
            self(loc + 1, cur, self);
            cur.pop_back();
        };
        string temp_string;
        generate_all_binary_palindromes(0, temp_string, generate_all_binary_palindromes);
        vector<int> ans;
        for (auto &num : nums) {
            int best = INT_MAX;
            for (auto &p : binary_pals) {
                best = min(best, (int)llabs(p - num));
            }
            ans.push_back(best);
        }
        return ans;
    }
};
