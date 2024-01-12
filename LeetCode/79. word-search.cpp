class Solution {
    private: 
    vector<int> dx = {0, 0,1,-1} ; 
    vector<int> dy = {1,-1,0,0};
public:

    bool inrange(int i , int j , int width , int hight  ) {
        return(i>=0 && i< hight && j>=0 && j< width); 
    } 

    bool sol(vector<vector<char>>&board, string& word , string &str , vector<vector<bool>> & vis ,int i , int j , int indx ) {
        
        if(!inrange(i,j,board[0].size() , board.size())) return false; 
        
        if (str == word ) return true; 
        if (str.size()>= word.size() || (str.size() &&str[str.size()-1] != word[str.size()-1])) return false;  
        if (board[i][j] != word[indx]) return false; 
        bool ans =0 ;
        
        vis[i][j] = true; 
        str.push_back(board[i][j]);
        
        for (int z =0 ; z < 4;  z++) {
            if(!inrange(i+dx[z],j+dy[z],board[0].size() , board.size()))  continue;                 
            if (!vis[i+dx[z]][j+dy[z]]) {
                ans|=sol(board ,word , str,vis, i+dx[z] , j+dy[z] , indx+1); 
            }
        }
        ans|=(str==word); 
        vis[i][j] = false; 
        str.pop_back();
        return ans; 
    }


    bool exist(vector<vector<char>>& board, string word) {
        if (word == "") return false; 
        string str ="";
        bool ans =0 ;  
        vector<vector<bool>> vis(board.size(), vector<bool>(board[0].size() , false )); 
        for(int i =0 ;i < board.size() ; i++){
            for(int j =0 ;j<board[0].size(); j++) {
                if(board[i][j] == word[0]) {
                    ans|=sol(board, word, str, vis, i, j, 0); 
                }
            }
        }
        return ans ; 
    }
};
