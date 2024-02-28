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

    void dfs(TreeNode* root , map<int , int > & lvl , int  level  ){
        if(root == nullptr) return;
        if(lvl.count(level)==0) lvl[level] = root->val; 
        dfs(root->left , lvl , level+1 ) ; 
        dfs(root->right , lvl , level+1 ); 
        return ; 
    }

    int findBottomLeftValue(TreeNode* root) {
        map<int ,int > lvls ; 
        dfs(root , lvls , 0); 
        return (*(lvls.rbegin())).second  ;
    }
};
