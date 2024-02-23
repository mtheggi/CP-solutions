class Solution {
public:
    int rob(vector<int>& nums) {
        
        int size = nums.size() ; 
        if(size == 1 ) return nums[0] ; 
        if(size == 2 ) return max(nums[0] , nums[1]); 
        vector<int> dp(nums.size()+2 ,0 ) , dp2(nums.size() +2 , 0 ); 
        dp[0]=nums[0];
        dp[1] = dp[0];
        dp2[0] =0 ; 
        dp2[1]=nums[1]; 
        for(int i =2 ;i < size-1 ; i++) dp[i]= max(nums[i]+dp[i-2] , dp[i-1]); 
        
        for(int i = 2; i < size ; i++ ) dp2[i]= max(nums[i]+dp2[i-2] , dp2[i-1]); 
        
        return max(dp[size-2] , dp2[size-1]);
    }
};
