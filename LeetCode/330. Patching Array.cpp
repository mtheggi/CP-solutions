class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int lastPatched = 0 ; 
        int added =0 ; 

        for(int i = 0 ;i < nums.size(); i++) {
            if(nums[i] != (lastPatched +1) ){
                lastPatched = lastPatched+1;  
                added++; 
            }
        }
        return added; 
    }
    
};
