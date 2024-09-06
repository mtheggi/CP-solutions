class Solution {
public:
    void dfs(vector<vector<int>> & grid2 , vector<vector<bool>> & vis , int i , int j, int n, int m,vector<pair<int ,int >> & island){
        if(!(i<n&&i>=0&&j>=0&&j<m))return; 
        if(vis[i][j] || grid2[i][j]==0) return;
        vis[i][j] = true; 
        island.push_back({i, j});
        dfs(grid2, vis, i+1 , j , n ,m , island); 
        dfs(grid2, vis, i-1 , j , n ,m , island); 
        dfs(grid2, vis, i , j+1 , n ,m , island); 
        dfs(grid2, vis, i , j-1 , n ,m , island); 
    }

    bool checkSubIsland(vector<vector<int>> & grid , vector<pair<int ,int >> & island) {
        
        for( int i =0 ; i<island.size() ; i++) {
            if(grid[island[i].first][island[i].second] == 0) return false; 
        }
        return true; 
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int ans =0 ;
        int n =grid2.size() ; 
        int m = grid2[0].size() ; 
        vector<vector<bool>> vis(n , vector<bool>(m,false)); 
        for(int i =0 ;i < n ; i++){
            for(int j =0; j < m ;j++){
                if(grid2[i][j] == 1 && vis[i][j] == false ) {
                    vector<pair<int ,int >> island; 
                    dfs(grid2 , vis , i, j,n,m , island); 
                    if(checkSubIsland(grid1, island)) ans++;
                
                }    

            
            }
        }



        return ans; 
    }
};
