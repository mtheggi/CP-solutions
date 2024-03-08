/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node * trHead = head ; 
        // creat new nodes ; 
        while(trHead != NULL){
            Node * newCopy = new Node(trHead->val); 
            newCopy->next = trHead->next != NULL ? trHead->next : NULL ; 
            trHead->next = newCopy; 
            trHead = trHead->next->next; 
        }
        // connect random ptrs 
        trHead = head;
        while(trHead != NULL) {
            trHead->next->random = (trHead->random) ? trHead->random->next : NULL; 
            trHead = trHead->next->next;  
        }
        trHead = head;
        Node* ans =( head == NULL) ? NULL : head->next; 
        // deparate linked lists 
        while(trHead!= NULL) {
            Node * tempPr = trHead->next->next ; 
            trHead->next->next = trHead->next->next== NULL ? NULL : trHead->next->next->next ; 
            trHead->next =  tempPr; 
            trHead = trHead->next ;      
        }
        return ans ; 
    }
};
