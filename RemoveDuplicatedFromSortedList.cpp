/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (head != nullptr){
            ListNode *cur = head;
            while (cur){
                ListNode *fwd = cur->next;
                while (fwd && cur->val == fwd->val){
                    fwd = fwd->next;
                }
                if (fwd == nullptr){
                    cur->next = nullptr;
                }
                else{
                    cur->next = fwd;
                }
                cur = cur->next;
            }
        }
        
        return head;
    }
};