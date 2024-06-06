class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxpos = 0 ; 
        for(int i =0 ;i < nums.size() ; i++) {
            if(i<= maxpos){
                maxpos= max(maxpos , i+nums[i]); 
            }else {
                break; 
            }
        }
        return maxpos>=nums.size()-1; 
    }
};
