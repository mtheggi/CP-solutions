class Solution {
public:
    bool valid( const int &  i ,const  int &  j ,const  int & n,const  int &  m ) {
        return (i<n && i>=0 && j<m && j>=0 ); 
    }

    void dfs(const vector<vector<int>> & grid , vector<vector<bool>> & vis, int i , int j , const int &  n , const int & m  ) {
        if (!valid(i,j, n ,m ) ) return; 
        if( vis[i][j] || grid[i][j] == 0) return ;
        vis[i][j] = true; 
        dfs(grid , vis , i+1 , j ,n ,m  ); 
        dfs(grid , vis , i , j+1, n, m  ); 
        dfs(grid , vis , i-1, j, n ,m  ); 
        dfs(grid , vis , i , j-1 , n, m ); 

    }

    int getNumConnected(const vector<vector<int>>& grid , const int & n , const int &m ) {
        vector<vector<bool>> vis (n+1 , vector<bool>(m+1 , false )); 
        int num =0; 
        for(int i =0 ;i < n ; i++)
            for(int j =0 ; j < m ; j++) {
                if( grid[i][j] == 1 && !vis[i][j]){
                    num++; 
                    dfs(grid, vis , i , j ,n, m );  
                }
            }
        return num; 
    }
    int minDays(vector<vector<int>>& grid) {
        int n= grid.size()  , m = grid[0].size() ; 
        if(getNumConnected(grid, n , m ) != 1 ) return 0; 
        for(int i =0 ;i < n ; i++)
            for(int j =0 ; j < m ; j++) {
                if(grid[i][j] == 1 ){
                    grid[i][j]=0; 
                    if(getNumConnected(grid, n , m ) != 1 ) return 1; 
                    grid[i][j]=1; 
                }
            }
        return 2; 
    }
};
