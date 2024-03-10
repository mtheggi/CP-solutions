class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        vector<vector<int>> dp = matrix ;
        int m = dp.size() , n =dp[0].size();   
        for(int i = 1;  i<m ; i++) {
            for(int j =0 ; j<n ; j++) {
                int up = dp[i-1][j] ; 
                int upleft = (j-1)<0 ? 1e9 : dp[i-1][j-1];  
                int upright=(j+1)>=n ? 1e9 : dp[i-1][j+1]; 
                dp[i][j] = min(up , min(upleft , upright)) + matrix[i][j]; 
            }
        } 
        int mn =  INT_MAX; 
        for(auto i : dp[m-1]) mn=min(mn , i ); 
        return mn ;
    }
};
