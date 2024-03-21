// messy DP need to be optimizied later 
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        s1 = "#" + s1; 
        s2 = "#" + s2;
        vector<vector<pair<int , int>>> dp(s1.size()+1, vector<pair<int , int>>(s2.size()+1,{0,0}) );  
        for(int i =1;i < s1.size() ; i++) {
            for(int j =1 ; j < s2.size() ; j++) {            
                if(s1[i] == s2[j]) {
                    dp[i][j].first = dp[i-1][j-1].first +1 ; 
                    dp[i][j].second=dp[i-1][j-1].second+s1[i]; 
                }
                vector<pair<int ,int >> setAscii = {dp[i][j-1],dp[i-1][j],dp[i][j]};
                dp[i][j].first = max({dp[i][j].first , dp[i-1][j].first , dp[i][j-1].first}); 
                for(auto p : setAscii){
                    if(dp[i][j].first ==p.first )
                        dp[i][j].second = max(dp[i][j].second, p.second ); 
                }
                
            }
        }
        int sum1  =0, sum2 =0 ; 
        for(int i =1 ;i < s1.size() ; i++)sum1+=s1[i];
        for(int i =1 ;i < s2.size() ; i++)sum2+=s2[i];
  
        return (sum1 + sum2 - (2 * dp[s1.size()-1][s2.size()-1].second));  
    }
};
