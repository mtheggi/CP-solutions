class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size()+1, vector<int>(text2.size()+1 , 0 )) ; 

        for(int i =0;i < text1.size() ; i++) {
            for(int j =0 ; j < text2.size() ; j++) { 
                if(i==0 || j ==0 ){
                    dp[i][j] = max({text1[i]==text2[j] , i>0 && dp[i-1][j], j>0 && dp[i][j-1]});
                    continue; 
                }else if(text1[i] == text2[j]) {
                    dp[i][j] = dp[i-1][j-1] +1 ; 
                }

                dp[i][j] = max({dp[i][j] , dp[i-1][j] , dp[i][j-1]}); 
            }
        }

        return dp[text1.size()-1][text2.size()-1];  
    }
};
