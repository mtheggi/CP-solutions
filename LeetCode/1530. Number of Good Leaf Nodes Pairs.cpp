/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode* ,  vector<TreeNode*>> graph ; 
    unordered_set<TreeNode*> leafNodes ;  
    void dfs(TreeNode * root ){
        if(root == nullptr ) return; 
        if(!root->left  && !root->right ){
            leafNodes.insert(root); 
        }
        if(root->left){
            graph[root].push_back(root->left); 
            graph[root->left].push_back(root); 
        }
        if(root->right) {
            graph[root].push_back(root->right); 
            graph[root->right].push_back(root); 
        }
        dfs(root->left) ;
        dfs(root->right) ;
    }

    int countBFS(TreeNode * src , int distance ) {
        queue<pair<TreeNode *, int>> q; 
        q.push({src,  0 }); 
        unordered_map<TreeNode* , bool > visited ; 
        visited[src] = true;   
        int ans =0 ; 
        while(q.size()) {
            TreeNode * frontNode = q.front().first  ;
            int lvl = q.front().second;  
            if(frontNode != src && leafNodes.count(frontNode) && (lvl) <= distance ) ans++;
            if(lvl > distance ) {
                q.pop(); 
                continue; 
            } 
            q.pop(); 
            for(auto &child : graph[frontNode]){
                if(!visited[child]){
                    visited[child] = true; 
                    q.push({child,lvl+1 }); 
                }
            }
        }

        return ans; 
    }


    int countPairs(TreeNode* root, int distance) {
        dfs(root);
        int ans =0  ;
        for(auto leaf : leafNodes)  {
            ans+=countBFS(leaf, distance ); 
        }


        return ans/2; 

    }
    

};
