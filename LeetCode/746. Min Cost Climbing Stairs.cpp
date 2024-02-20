class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<long long > dp(cost.size() +2 , 0 );
        for(int i =0 ;i < cost.size() ; i++) dp[i]=cost[i];   

        for(int i = 2 ; i<= cost.size() ; i++) {
            dp[i] = min(dp[i-1],dp[i-2]) + dp[i]; 
        }
        return dp[cost.size()]; 


    }
};
