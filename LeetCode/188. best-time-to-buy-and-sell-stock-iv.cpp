class Solution {
public:
    int rec_maxProfit(int day , int k, int buyorsell ,   vector<int>& prices , vector<vector<vector<int>>>&dp){
        if( day >= prices.size() ) return 0;  
        int & ret = dp[day][k][buyorsell]  ; 
        if(ret != -1e9 ) return ret;  
        int option1 =-1e8 , option2 = -1e8 , option3 = -1e8  ; 
        if(k >= 1 && buyorsell==0 )
            option1 = prices[day] + rec_maxProfit(day+1 , k-1,1 , prices , dp ) ; // sell 
        if(buyorsell==1  )
            option2 = -prices[day] + rec_maxProfit(day+1 ,k ,0, prices , dp ) ;//buy  
        

        option3 = rec_maxProfit(day+1 , k, buyorsell, prices, dp  ) ; // do nothing 
        return ret  = max(option1 , max(option2 , option3 )); 
    }


    int maxProfit(int k, vector<int>& prices) {
  
        vector<vector<vector<int>>> dp(prices.size() , vector<vector<int>>(101 ,  vector<int>(2, -1e9 ))); 
        
        return rec_maxProfit(0, k, 1,  prices , dp  ); 
    }
};
