class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1 ) return nums[0]; 
        vector<int> dp(nums.size()+2 , 0 ) ; 
        for(int i =0 ;i < nums.size() ; i++) dp[i] = nums[i]; 
        dp[1] = max(dp[1] , dp[0]);
        for(int i = 2;  i< nums.size() ; i++) {
            dp[i]= max(dp[i]+dp[i-2] , dp[i-1]); 
        }
        return dp[nums.size() -1];
    }
};
