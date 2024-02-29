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
    void dfs(TreeNode* root,map<int ,vector<int>> & nodes , int lvl ) {
        if (root == nullptr ) return ; 
        nodes[lvl].push_back(root->val); 
        dfs(root->left , nodes , lvl+1 ); 
        dfs(root->right , nodes , lvl+1); 
        return ;
    }
    bool isEvenOddTree(TreeNode* root) {
        map<int ,vector<int>> nodes;  
        dfs(root , nodes , 0 ) ;
        auto it = nodes.begin();  
        for(int i =0 ;i < nodes.size() ; i++) {
            if(i%2){
                set<int> newvec(it->second.begin() , it->second.end());
                if(newvec.size() != it->second.size()) return false;  
                reverse(it->second.begin() , it->second.end());
                if(!is_sorted(it->second.begin() , it->second.end())) return false;
                for(auto el : it->second ){
                    if(el%2) return false; 
                }
            }else {
                set<int> newvec(it->second.begin() , it->second.end());
                if(newvec.size() != it->second.size()) return false;  
                if(!is_sorted(it->second.begin() , it->second.end())) return false;
                for(auto el : it->second ){
                    if(el%2==0) return false; 
                }
                
            }
            it++;
        }  
        return true; 

    }
};
