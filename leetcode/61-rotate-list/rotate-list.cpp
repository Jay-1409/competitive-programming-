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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr)
            return head;
        ListNode* new_head = head;
        int len = 1;
        while(head->next != nullptr) {
            head = head->next;
            len++;
        }
        head->next = new_head;
        k = len - (k % len);
        while(k--) {
            new_head = new_head->next;
            head = head->next;
        }
        head->next = nullptr;
        return new_head;
    }
};