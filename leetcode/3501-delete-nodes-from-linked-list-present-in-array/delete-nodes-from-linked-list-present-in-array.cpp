/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int,int> mp;
        for(auto &I :  nums) {
            mp[I]++;
        }
        ListNode* prev = new ListNode(-1);
        ListNode* copy = prev;
        while(head != nullptr) {
            auto remove_node = [&]() -> int {
                prev->next = head->next;
                head = head->next;
                return 0;
            };
            if(mp[head->val]) {
                // to be removed
                if(remove_node() == 1) {
                    break;
                }
            } else {
                prev->next = head;
                prev = prev->next;
                head = head->next;
            }
        }
        return copy->next;
    }
};