class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size() +2 , false );  
        dp[0] = true; 
        s="$" + s; 
        
        for(int i = 1 ; i <= s.size() ; i++) {    
            for(auto w : wordDict) {
                int wsize = w.size(); 
                if((i-wsize ) >=0  && dp[i-wsize] && (s.substr(i-wsize+1 , wsize)==w)){
                    dp[i] =true; 
                    break;
                } 
            }
        }
  
        return dp[(int)s.size()-1];
    }
};
