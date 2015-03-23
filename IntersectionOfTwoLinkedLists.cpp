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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr){
	        return nullptr;
        }
        
        ListNode *curr1 = headA;
        ListNode *curr2 = headB;
        ListNode *tail1 = nullptr;
        ListNode *tail2 = nullptr;
        
        while (curr1 != curr2) {
            if (tail1 != nullptr && tail2 != nullptr && tail1 != tail2){
                return nullptr;
            }
            
        	if (curr1->next == nullptr && tail1 == nullptr){
        		tail1 = curr1;
        		curr1 = headB;
            }
            else if (curr1 == tail1){
            	curr1 = headB;
            }
            else if (curr1 == tail2){
            	curr1 = headA;
            }
            else{
            	curr1 = curr1->next;
            }
            if (curr2->next == nullptr && tail2 == nullptr){
	        	tail2 = curr2;
	        	curr2 = headA;
            }
            else if (curr2 == tail2){
            	curr2 = headA;
            }
            else if (curr2 == tail1){
            	curr2 = headB;
            }
            else{
            	curr2 = curr2->next;
            }
        }
        
        if (curr1 == curr2) return curr1;
        
        return nullptr;
        
    }
};
