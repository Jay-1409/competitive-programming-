/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxProduct(TreeNode* root) {
        const long long MOD = 1e9 + 7;
        long long sum_total = 0;
        auto sum_dfs = [&](TreeNode* cur, auto && self) -> void {
            if(!cur) 
                return;
            sum_total = (sum_total + cur->val);
            self(cur->right, self);
            self(cur->left, self);
        };
        TreeNode* _root = root;
        sum_dfs(_root, sum_dfs);
        long long maxe = 0;
        auto dfs = [&](TreeNode* cur, auto && self) -> int {
            if(!cur)
                return 0;
            long long left  = self(cur->left, self);
            long long right = self(cur->right, self);
            long long keep_left = (1LL * (sum_total - left) * left);
            long long keep_right = (1LL * (sum_total - right) * right);
            //cout << sum_total << " " << keep_left << " " << keep_right << endl;
            maxe = max({maxe, keep_left, keep_right});
            return (cur->val + (left + right));
        };  
        dfs(root,dfs);
        return maxe % MOD;
    }
};