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
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        auto dfs = [&](TreeNode* cur, auto && self) -> int {
            if(cur) {
                int left = max(0, self(cur->left, self));
                int right = max(0, self(cur->right, self));
                ans = max(ans, (left + right) + cur->val);
                return max(left, right) + cur->val;
            }
            return 0;
        };
        dfs(root, dfs);
        return ans;
    }
};