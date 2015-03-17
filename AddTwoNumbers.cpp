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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if (l1 == nullptr && l2 == nullptr) return nullptr;
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;
        
        ListNode * sum = nullptr;
        ListNode * head = nullptr;
        int overflow = 0;
        int val = 0;
        
        while (l1 || l2 || overflow){
            val = 0;
            if (l1){
                val += l1->val;
                l1 = l1->next;
            }
            if (l2){
                val += l2->val;
                l2 = l2->next;
            }
            
            val += overflow;
            
            if (val / 10){
                overflow = val/10;
                val = val%10;
            }
            else {
                overflow = 0;
            }
            
            ListNode *node = new ListNode(val);
            if (sum != nullptr){
                sum->next = node;
                sum = sum->next;
            }
            else{
                sum = node;
                head = node;
            }
            
        }
        
        return head;
    }
};