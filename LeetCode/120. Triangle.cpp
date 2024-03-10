class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp = triangle;
        
        for(int i = 1 ;i<dp.size() ; i++) {
            for(int j =0 ; j< dp[i].size() ; j++) {
                if(j==0){
                    dp[i][j] = dp[i-1][j] + triangle[i][j]; 
                }else if(j+1  == dp[i].size()){
                    dp[i][j] = dp[i-1][j-1] + triangle[i][j]; 
                }else{
                    dp[i][j] = min(dp[i-1][j] ,dp[i-1][j-1]) + triangle[i][j]; 
                }
            }
        } 
        int mn = INT_MAX ; 
        for(auto i :  dp[dp.size()-1] ) mn = min(mn , i ); 
        return mn ;
    }
};
