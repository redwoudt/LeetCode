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
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr){
            return nullptr;
        }
        
        ListNode * slow = head;
        ListNode * fast = head;
        while (fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow){
                //circular queue
                break;
            }
        }
        
        if (fast == nullptr || fast->next == nullptr){
            return nullptr;
        }
        else{
            ListNode * curr = head;
            while (curr != slow){
                curr = curr->next;
                slow = slow->next;
            }
            
            return curr;
            
        }
        
    }
};