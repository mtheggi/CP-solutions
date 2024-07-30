class Solution {
public:
    int minimumDeletions(string s) {
        vector<int>dp(s.size()+1,0);
        int numberOfBs =(s[0]=='b');
        for(int i =1;i< s.size();  i++) {
            if(s[i] == 'b' ) {
                dp[i]=dp[i-1]; 
                numberOfBs++; 
            }else{
                dp[i] = min(dp[i-1]+1, numberOfBs); 
            }
        } 
        return dp[s.size()-1]; 
    }
};
