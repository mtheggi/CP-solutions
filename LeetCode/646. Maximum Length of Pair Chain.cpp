class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());
        vector<int> dp(pairs.size()+2);
        for(int i =0 ;i < pairs.size() ; i++)dp[i]=1 ; 
        int mx =1;
        for(int i =1 ; i<pairs.size() ; i++) {
            for(int j =i-1; j>=0; j--){
                if(pairs[i][0] >pairs[j][1]){
                    dp[i]=max(dp[i] , dp[j]+1); 

                }
            }
            mx = max(dp[i] , mx ); 
        }

        return mx; 
    }
};
