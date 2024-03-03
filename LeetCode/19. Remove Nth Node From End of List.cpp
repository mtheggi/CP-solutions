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
            ListNode * temp = head ; 
            ListNode * temp2= head ; 
            int size =0 ; 
            while(temp) {
                size++; 
                temp= temp->next ;
            }
            if(size ==1  ) return nullptr;
            int order = size- n +1 ; 
            if(order == 1 ) {
                head= head->next; 
                return head; 
            }
            int curr= 1; 
            while(temp2) {
                if(curr == (order-1) ) {
                    temp2->next = temp2->next == nullptr ? nullptr : temp2->next->next; 
                    break; 
                }
                temp2 = temp2->next; 
                curr++; 
            }
            return head; 
    }
};
