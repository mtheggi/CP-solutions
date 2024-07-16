/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* getLCA(struct TreeNode * root , int start , int dest ) {
    if(root == NULL) return NULL ; 
    
    if(root->val == start || root->val == dest) return root ; 

    struct TreeNode * leftSide = getLCA(root->left , start , dest ); 
    struct TreeNode * rightSide= getLCA(root->right , start , dest ); 

    if ((leftSide != NULL && rightSide!=NULL) ) return root; 
    return leftSide ==NULL ? rightSide  : leftSide ; 

}

bool getPathDFS(char * ans , int * index , int dest, struct TreeNode * root ) {
    
    if(root->val == dest ) return true; 
    if(root->left && getPathDFS(ans , index , dest, root->left )) {
        ans[(*index)++] = 'L'; 
    }else if(root->right && getPathDFS(ans , index , dest, root->right )){
        ans[(*index)++] = 'R'; 
    } 
    return (*index) > 0; 
}

char* getDirections(struct TreeNode* root, int startValue, int destValue) {

    char * ans = (char * ) malloc(1e5); 
    char * secondAns = (char * ) malloc(1e5); 
    int i =0 , si =0  ; 
    struct TreeNode * LCA =  getLCA(root , startValue , destValue); 

    if(LCA->val == startValue) {
        getPathDFS(ans, &i , destValue , LCA );
    }else if(LCA->val == destValue) {
        getPathDFS(ans, &i , startValue , LCA );  
        for(int j =0; j < (i) ; j++) ans[j] = 'U';
    }else{
        getPathDFS(ans, &i , destValue , LCA );
        getPathDFS(secondAns, &si , startValue, LCA );
        for(int j =i; j < (i+si) ; j++) ans[j] = 'U';

    }

    ans[i+si] = '\0'; 
    int start =0 , end = (i+si)-1; 
    
    while(start < end ){
        char temp = ans[start]; 
        ans[start] = ans[end]; 
        ans[end] = temp; 
        start++;
        end--; 
    }

    return ans ; 
}
