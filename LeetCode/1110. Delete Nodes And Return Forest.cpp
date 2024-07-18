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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        map<int , bool> is_delete;  
        for(auto num : to_delete ) is_delete[num] = true; 
        vector<TreeNode*> ans; 
        queue<TreeNode*> q ; 
        map<TreeNode * , bool> deleted; 
        q.push(root); 
        while(q.size()) {
            TreeNode * front= q.front(); 
            q.pop(); 
            if(front->left){
                q.push(front->left); 
                if(is_delete[front->left->val])
                    front->left=nullptr; 
            }
            if(front->right ){
                q.push(front->right); 
                if(is_delete[front->right->val])
                    front->right=nullptr; 
            }
            if(is_delete[front->val]){
                if(front->left) {
                    ans.push_back(front->left); 
                }
                if(front->right) {
                    ans.push_back(front->right); 
                }


            }else if(ans.empty()){
                ans.push_back(front); 
            }      
        }              
        return ans; 
    }

};
