class Solution {
public:
   int longestPalindromeSubseq(string s) {
        vector<vector<int>> dp(s.size() , vector<int>(s.size() , 0 ));
        for (int len = 1 ; len <=s.size() ; len++){
            for(int i =0 ;i+len -1 < s.size() ; i++) {
                int j = i+len -1 ;
                 if(i==j) {dp[i][j]= 1; continue; }
                if(s[i] == s[j]) {
                    dp[i][j] = 2 + dp[i+1][j-1];
                }else {
                    dp[i][j]= max(dp[i][j-1] , dp[i+1][j]);
                }
            }
        }
 
        return dp[0][s.size()-1 ];
    }
};
