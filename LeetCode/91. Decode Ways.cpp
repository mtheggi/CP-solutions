class Solution {
public:
    int convert( char t,  char u ) {
        return (t-'0')*10 + (u-'0') ;  
    }
    int numDecodings(string s) {
        if(s[0] == '0' ) return 0 ;
        for(int i =1 ;i <s.size() ; i++)
            if((s[i] == '0' && (s[i-1] == '0' || s[i-1] > '2'))  ) return 0;  
   
        vector<int> dp(s.size()+1 , 0 ); 
        dp[0] = 1;
        dp[1]= (convert(s[0] , s[1])>26 ) ? 1 : 2 ;
        if(s[1] == '0') {
            dp[1] =1 ;
            dp[0] =0 ; 
        } 
        for(int i =2  ;i< s.size() ; i++) {
            if(s[i] == '0') {  
                dp[i] = dp[i-2]; 
                dp[i-1] =0;
            }else if(convert(s[i-1] , s[i]) > 26) {
                dp[i] = dp[i-1]; 
            }else {
                dp[i] = dp[i-1] + dp[i-2]; 
            }
        }
        return dp[s.size()-1];
    }
};
