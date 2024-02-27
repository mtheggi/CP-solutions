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
    int getlevel(TreeNode * root  , int lvl) {
        if(root == nullptr ) return lvl ;
        int lvl1 = getlevel(root->right , lvl+1 ); 
        int lvl2 = getlevel(root->left , lvl+1 ); 
        return(max(lvl1 , lvl2 ));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root== nullptr ) return 0; 
        int leftlvl = getlevel(root->left , 0 );
        int rightlvl = getlevel(root->right , 0 ); 
        int mx = leftlvl + rightlvl;
        int leftMx = diameterOfBinaryTree(root->left); 
        int rightMx = diameterOfBinaryTree(root->right ); 

        return max(leftMx , max(mx , rightMx)); 
    }
};
