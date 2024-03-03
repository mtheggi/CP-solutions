




/*Iterative solution */
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
            if(amount == 0 ) return 0 ;
            vector<int> dp(amount+3 , INT_MAX );
            dp[0]=0;
            for(int i =1 ; i <= amount ; i++) {
                for(auto coin : coins ) {
                    if(i-coin >=0 && coin <= amount && dp[i-coin] != INT_MAX )
                        dp[i] = min(dp[i] , dp[i-coin] + 1); 
                }
            }
            return dp[amount] ==INT_MAX ? -1 : dp[amount] ; 

   }
};



/*Recursive Solution */
class Solution {
public:
    int solve(vector<int> & coins , int amount , vector<int> &dp ) {
        if(amount < 0 ) return INT_MAX ; 
        if(amount == 0) {
            return 0 ; 
        }
        if(~dp[amount])return dp[amount]; 
        int mn =INT_MAX; 
        for(int i =0 ;i < coins.size() ; i++) {
            mn = min(mn , solve(coins,   amount-coins[i] , dp)); 
        }
        if(mn != INT_MAX) {
              mn+=1 ; 
        }
        return  dp[amount] = mn;
    }

    int coinChange(vector<int>& coins, int amount) {
            if(amount == 0 ) return 0 ;
            vector<int> dp(amount+3 , -1 );
            int sol = solve(coins  ,amount,dp);

            return sol ==INT_MAX ? -1 : sol ; 

   }
};
