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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if (root == nullptr) return nullptr;
        vector<vector<int>> level_order;
        queue<pair<TreeNode*,int>> q;
        TreeNode* _root = root;
        q.push({_root, 0});
        while(!q.empty()) {
            auto [node, depth] = q.front(); q.pop();
            if (depth >= (int)level_order.size()) {
                level_order.emplace_back();
            }
            level_order[depth].push_back(node->val);
            if(node->right) {
                q.push({node->right, depth + 1});
            }
            if(node->left) {
                q.push({node->left, depth + 1});
            }
        }
        set<int> deapest_root;
        for(auto &I : level_order.back()) {
            deapest_root.insert(I);
        }
        int max_fav_root_depth = 0;
        TreeNode* lca = root;
        auto dfs = [&](TreeNode* cur, int depth, auto && self) -> set<int> {
            auto insert_minor_set_into_major_set = [&](set<int> &minor, set<int> &major) -> void {
                for(auto &I : minor) {
                    major.insert(I);
                }
            };  
            auto is_current_node_one_of_deapest = [&](TreeNode* _cur) -> bool {
                if(deapest_root.find(cur->val) != deapest_root.end()) {
                    return true;
                }
                return false;
            };
            if(!cur) 
                return {};
            set<int> cur_good_ele;
            if(is_current_node_one_of_deapest(cur)) {
                cur_good_ele.insert(cur->val);
            }
            set<int> l,r;
            if(cur->left) {
                l = self(cur->left, depth + 1, self);
            }
            if(cur->right) {
                r = self(cur->right, depth + 1, self);
            }
            insert_minor_set_into_major_set(l, cur_good_ele);
            insert_minor_set_into_major_set(r, cur_good_ele);
            if(cur_good_ele == deapest_root && depth > max_fav_root_depth) {
                max_fav_root_depth = depth;
                lca = cur;
            }
            return cur_good_ele;
        };
        TreeNode* __root = root;
        set<int> res = dfs(__root, 0, dfs);
        return lca;
    }
};