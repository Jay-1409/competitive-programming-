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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int location = 1;
        ListNode* previous_node = nullptr;
        ListNode* save_head = head;
        int len = 0;
        ListNode* temp = head;
        while(temp) {
            len++;
            temp = temp->next;
        }
        cout << len << " " << len - n + 1 << endl;
        n = len - n + 1; 
        if(n == 1)
            return save_head->next;
        while(location <= len) {
            if(location == n) {
                if(head != nullptr)
                    previous_node->next = head->next;
                else
                    previous_node->next = nullptr;
                break;
            }
            previous_node = head;
            head = head->next;
            location++;
        }
        return save_head;
    }
};