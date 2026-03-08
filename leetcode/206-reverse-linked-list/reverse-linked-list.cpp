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
    ListNode* reverseList(ListNode* head) {
        ListNode* dummy_node = nullptr;
        auto rev = [&](ListNode* previous_node, ListNode* cur_head, auto && self) -> ListNode* {
            if(cur_head == nullptr) 
                return previous_node;
            ListNode* temp = cur_head->next;
            cur_head->next = previous_node;
            return self(cur_head, temp, self);  
        };
        return rev(dummy_node, head, rev);
    }
};