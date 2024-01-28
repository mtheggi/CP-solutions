class Solution {
public:
    bool inborder(int i , int j , int csize , int rsize ){ return(i<rsize && i >=0 && j <csize && j>= 0 ); }
    
    void dfs(vector<vector<char>>& grid  , vector<vector<bool>>& visited, int i , int j ){
            if(!inborder(i,j,grid[0].size(), grid.size()) ) return ;
            if(grid[i][j] == '0') return; 
            if(visited[i][j]) return;  
            visited[i][j] =true; 
            
            dfs(grid , visited , i+1 , j ); 
            dfs(grid , visited , i-1 , j );
            dfs(grid , visited , i , j+1 );
            dfs(grid , visited , i , j-1 );
        
    }

    int numIslands(vector<vector<char>>& grid) {
        int cnt =0; 
        vector<vector<bool>>  visited(grid.size() , vector<bool>(grid[0].size(),  0 )) ;  
  
        for(int i = 0 ;i < grid.size() ; i++) {
            for(int j =0 ; j < grid[0].size() ; j++){
                if(!visited[i][j] && grid[i][j] == '1'){
                    cnt++; 
                    dfs(grid , visited, i , j ); 
                }
            }
        }
        return cnt;

    }
};
