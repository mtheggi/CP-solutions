class Solution {
public:
    bool canPartition(vector<int>& nums) {
        if(nums.size() ==1 ) return false ; 
        int sum =0 ; 
        for (auto i : nums ) sum+=i; 
        if(su   m&1) return false; 
        int target =sum/2 ; 
        vector<bool> dp(sum+2 , false ); 
        dp[0] = true; 
        for(auto num : nums) {
            set<int> st ; 
            for(int i =0; i <= target; i++){
                if(dp[i]) {
                    st.insert(i+num); 
                }
            } 
            for(auto indx : st ) {
                dp[indx] = true; 
            }
        }       
        return dp[target]; 
    }
};
