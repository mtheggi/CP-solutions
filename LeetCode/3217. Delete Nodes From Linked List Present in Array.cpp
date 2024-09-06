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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
      
    unordered_map<int , bool> exists ; 
    for(auto num : nums) exists[num]=true; 
    ListNode * newHead = head ; 
    ListNode * prev= NULL ; 
    while(newHead) {
        if(exists[newHead->val]){
            if(prev == NULL) { // first element ; 
                prev =newHead; 
                newHead=newHead->next; 
                head = newHead ; 
                delete prev; 
                prev = NULL;  
            }else {
                prev->next=newHead->next;  
                newHead=newHead->next; 
            }
        }else{
            prev=newHead; 
            newHead=newHead->next; 
        }
    }
    return head; 




    }
};
