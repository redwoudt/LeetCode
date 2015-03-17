/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class CompareValue {
public:
    bool operator()(ListNode * & l1, ListNode * & l2)
    {
        if (l1 != NULL && l2 != NULL){
            if (l1->val > l2->val) return true;
        }
        return false;
    }
};

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        priority_queue <ListNode *, vector<ListNode *>, CompareValue> record;
        
        for (const auto & list : lists){
            ListNode * curr = list;
            while (curr != NULL){
                record.push(curr);
                curr = curr->next;
            }
        }
        
        ListNode * mergedList = NULL;
        if (!record.empty()){
            mergedList = record.top();record.pop();
        }
        ListNode * trav = mergedList;
        
        while (!record.empty() && trav != NULL){
            trav->next = record.top();record.pop();
            trav = trav->next;
        }
        if (trav != NULL){
            trav->next = NULL;
        }
        
        return mergedList;
        
    };
    
};