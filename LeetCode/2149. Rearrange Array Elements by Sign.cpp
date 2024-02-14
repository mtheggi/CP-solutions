class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans , pos,  neg ; 
        for(int i =0 ;i < nums.size() ; i++) {
            if(nums[i] > 0 ) pos.push_back(nums[i]) ; 
            else neg.push_back(nums[i]); 
        }
        int posIndx =0 , negIndx=0; 
        for(int i =0 ;i < nums.size() ; i++) {
            if(!(i%2)){
                ans.push_back(pos[posIndx]); 
                posIndx++; 
            }else {
                ans.push_back(neg[negIndx]) ; 
                negIndx++; 
            }
        }

        return ans; 
    }
};
