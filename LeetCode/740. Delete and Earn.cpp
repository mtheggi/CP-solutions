class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
     map<int , int > freq; 
     for(auto num : nums) freq[num]++; 
     set<int> st(nums.begin() , nums.end()); 
     vector<int> UniqueNums(st.begin() , st.end()); 
     vector<int> dp(st.size()+2, false); 
     dp[0]=UniqueNums[0]*freq[UniqueNums[0]]; 
     for(int i =1 ;i <UniqueNums.size() ; i++) {
         if(UniqueNums[i]-UniqueNums[i-1] > 1 ) {
             dp[i]=dp[i-1] + UniqueNums[i]*freq[UniqueNums[i]]; 
         }else{
             int val  ; 
            if(i>=2)
                val = dp[i-2] + UniqueNums[i]*freq[UniqueNums[i]]; 
            else
                val = UniqueNums[i]*freq[UniqueNums[i]]; 

             dp[i] = max(dp[i-1] , val); 
         }
     }

        return dp[st.size()-1]; 
    }
};
