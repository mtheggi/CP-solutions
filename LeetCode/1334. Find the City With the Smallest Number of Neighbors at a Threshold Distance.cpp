class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

        vector<vector<long long >>dp(n+1  , vector<long long >(n+1, 1e8)); 
        for(int i =0;i <edges.size() ; i++) {
            dp[edges[i][0]][edges[i][1]] = edges[i][2]; 
            dp[edges[i][1]][edges[i][0]] = edges[i][2];  
        }
        
        for(int i =0 ;i < n ; i++) dp[i][i]= 0; 
        
        for(int k =0 ;k < n ;k++) {
            for(int i = 0; i<n ; i++) {
                for(int j =0; j <n ; j++ ){
                    if(i==k || j==k ) continue; 
                    dp[i][j] = min(dp[i][j] , dp[i][k] + dp[k][j] ); 
                }
            }
        }
        int ans =0 , cnt = 0 , mnCnt= INT_MAX; 
        for(int i =n-1 ; i>=0 ;i--){
            cnt=0; 
            for(int j=0 ; j <n ; j++) {
                if(dp[i][j] <=distanceThreshold) {
                    cnt++; 
                }
            }
            if(cnt< mnCnt) {
                mnCnt=cnt;
                ans=i; 
            }
        }
        return ans; 
    }
};
