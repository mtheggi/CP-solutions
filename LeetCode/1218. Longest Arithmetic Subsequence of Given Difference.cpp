class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size() ; 
        map<int,int>dp; 
        dp[arr[0]] =1; 
        int ans =1; 
        for(int i =1 ; i< n ; i++) {
            int prev= arr[i]-difference; 
            if(dp[prev]){
                dp[arr[i]]= max(dp[arr[i]] , dp[prev]+1); 
                ans= max(dp[arr[i]] , ans ); 
            }else {
                dp[arr[i]]=1; 
            }
        } 
        return ans; 
    }
};
