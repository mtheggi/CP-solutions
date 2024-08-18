class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int m = points.size() , n=points[0].size(); 
        vector<vector<long long>> dp(m , vector<long long >(n));
        for(int i =0 ; i < n ; i++) dp[0][i]=points[0][i];
        

        for(int i =1 ; i < m; i++) {
            
            vector<long long > prefix(n+1, 0 ) ,  suffix(n+1, 0 ) ;
            prefix[0] = dp[i-1][0]; 
            suffix[n-1]=dp[i-1][n-1]; 
            dp[i][0] = points[i][0]; 
            for(int col =1 ; col < n ; col++) {
                dp[i][col] = points[i][col]; 
                prefix[col] = max(prefix[col-1]-1,dp[i-1][col]); 
            } 
            for(int col =n-2 ; col>=0 ; col--) {
                suffix[col] = max(suffix[col+1]-1,dp[i-1][col]);   
            } 
                  
            for(int j = 0 ; j < n ;j++) {
                dp[i][j]+=max(prefix[j], suffix[j]);                  
            }
        }

        return *max_element(dp[m-1].begin(), dp[m-1].end());

    }
};
