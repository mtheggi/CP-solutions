/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* bfs(Node * node   ) {
        map<Node* , Node * > clone ; 
        queue<Node * >  q;
        map<Node * , bool > vis ;   
        q.push(node);  
        clone[node] = new Node(node->val);                 
        vis[node]= true; 
        while(q.size()) {
            Node * front = q.front(); 
            q.pop(); 
            for( auto i : front->neighbors) {
                if(!vis[i]){
                    Node * newchild = new Node(i->val ) ;  
                    clone[i]= newchild; 
                    clone[front]->neighbors.push_back(newchild); 
                    vis[i]=true; 
                    q.push(i); 
                }else{
                    clone[front]->neighbors.push_back(clone[i]); 
                }
            
            }
        }

        // for(auto i : clone ) {
        //     cout << "parent " << i.second->val << endl; 
        //     cout << "child" << endl; ; 
        //     for (auto j : i.second->neighbors) {
        //         cout << j->val << " " << endl; 
        //     }
        // }
        // cout << "teest "<< clone[node]->val << endl; 

        return clone[node];

    }




    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL; 
        return bfs(node );  

    }
};
