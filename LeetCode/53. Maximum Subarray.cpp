class Solution {
public:
// kadan's 
    int maxSubArray(vector<int>& nums) {
        int currentMax = nums[0] , globalMax = currentMax; 
        for(int i =1 ;i < nums.size() ; i++) { 
            currentMax= max(nums[i] , currentMax + nums[i]); 
            globalMax=max(currentMax , globalMax); 
        }
        return globalMax ;
    }
};
