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
    TreeNode* createBinaryTree(vector<vector<int>> &descriptions) {
        int size = descriptions.size() ;
        map<int , TreeNode* > tree;
        map<int, bool> isChild;
        for(int i =0 ;i <size ; i++) {
            int parent =descriptions[i][0];
            int child = descriptions[i][1];  
            TreeNode * childNode ;
            TreeNode * parentNode ;
            if(tree.count(parent)){
                
                if(tree.count(child)) {
                    childNode=tree[child];
                }else {
                    childNode = new TreeNode(child);
                }
                parentNode = tree[parent];
                if(descriptions[i][2] == 1){
                    parentNode->left = childNode;
                }else {
                    parentNode->right = childNode;
                }
            }else {
                if(tree.count(child)) {
                    childNode=tree[child];
                }else {
                    childNode = new TreeNode(child);
                }
                if(descriptions[i][2] == 1 ){
                    parentNode = new TreeNode(parent ,childNode , nullptr);
                }else {
                    parentNode = new TreeNode(parent ,  nullptr,childNode);
                }

            }
            tree[parent]= parentNode;
            tree[child] = childNode;
            isChild[descriptions[i][1]]=  true;
        }
        TreeNode * ans ;
        for(auto i : tree ) {
            if(isChild[i.first] == false) {
                cout << i.first << endl;
                ans=  i.second;
            }
        }

    return ans;
    }

};
