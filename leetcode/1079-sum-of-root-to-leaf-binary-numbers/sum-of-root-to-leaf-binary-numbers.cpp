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
    int sumRootToLeaf(TreeNode* root) {
        int sum = 0;
        auto dfs = [&](int val, TreeNode* cur, auto && self) -> void {
            val <<= 1;
            val |= (cur->val);
            if(cur->left) {
                self(val, cur->left, self);
            }
            if(cur->right) {
                self(val, cur->right, self);
            }
            if(cur->right == nullptr && cur->left == nullptr) {
                sum += val;
            }
        };
        dfs(0, root, dfs);
        return sum;
    }
};