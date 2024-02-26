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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry =0 ; 
        ListNode* ans = new ListNode(); 
        ListNode* temp = ans; 
        while(l1 != nullptr || l2 != nullptr ) {
            int val1 =  l1==nullptr ? 0 : l1->val ; 
            int val2 =  l2==nullptr ? 0 : l2->val ;
            int sumVal = val1 + val2 + carry; 
            if(sumVal > 9 )
            { carry = 1 ; sumVal = sumVal%10 ; } 
            else carry =0 ;
            temp->val = sumVal ; 
            l1 = l1==nullptr? nullptr :l1->next; 
            l2 = l2==nullptr? nullptr : l2->next ;
            if(l1 != nullptr || l2 != nullptr){
                temp->next = new ListNode(); 
                temp= temp->next; 
            }

        }
        if(carry){
            temp->next=new ListNode(1);
        }
        return ans; 
    }
};
