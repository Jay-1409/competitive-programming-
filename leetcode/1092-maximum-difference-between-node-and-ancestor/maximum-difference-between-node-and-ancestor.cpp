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
    int maxAncestorDiff(TreeNode* root) {
        int ans = 0;
        auto findChildMax = [&](TreeNode* cur, auto && self) -> pair<int,int> {
            if (!cur)
                return {INT_MAX, INT_MIN};  
            auto left = cur->left ? self(cur->left, self) : make_pair(cur->val, cur->val);
            auto right = cur->right ? self(cur->right, self) : make_pair(cur->val, cur->val);
            int mn = min({cur->val, left.first, right.first});
            int mx = max({cur->val, left.second, right.second});
            ans = max(ans, max(abs(cur->val - mn), abs(cur->val - mx)));
            return {mn, mx};
        };
        findChildMax(root, findChildMax);
        return ans;
    }
};
