class Solution {
public:
    int minSteps(int n) {
        vector<long long > dp(n+6,0); 
        dp[1] =0;dp[2] =2 ; dp[3] = 3 ; dp[4]=4;

        for(int i = 5; i<=n ;i++) {
            for(int j = i-1 ; j>=1 ; j--) {
                if((i%j)==0 ) {
                    long long rem = i/j;
                    dp[i]=dp[j] + rem; 
                    break; 
                }
            }
        }

        return dp[n]; 
  
  
    }
};
