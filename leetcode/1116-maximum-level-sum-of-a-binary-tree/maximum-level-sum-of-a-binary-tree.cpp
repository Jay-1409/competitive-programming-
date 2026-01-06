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
    int maxLevelSum(TreeNode* root) {
        vector<int> level_sum;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while(!q.empty()) {
            auto [u, depth] = q.front(); q.pop();
            if(depth >= level_sum.size()) {
                level_sum.emplace_back();
            }
            level_sum[depth] += u->val;
            if(u->right) {
                q.push({u->right, depth + 1});
            }
            if(u->left) {
                q.push({u->left, depth + 1});
            }
        }
        int level = -1;
        int best_sum = INT_MIN;
        for(int i = 0; i < (int)level_sum.size(); ++i) {
            //cout << i << " " << level_sum[i] << endl;
            if(level_sum[i] > best_sum) {
                level = i;
                best_sum = level_sum[i];
            }
        }
        return ++level;
    }
};