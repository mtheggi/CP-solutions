class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int cntOnes=0, n=nums.size(); 
        for(auto & num : nums) { if(num==1) cntOnes++; }
        int start=0 ,end = 0,windowOnes =(nums[0]==1), mnSwaps =INT_MAX;  
        while(start<=end) {
            if(start >= nums.size()) break; 
            if(end-start+1 != cntOnes && cntOnes!=0  ) { 
                if(nums[(end+1)%n] == 1) windowOnes++;  
                end++; 
            }else{
                if(nums[(end+1)%n] == 1) windowOnes++; 
                if(nums[start] == 1) windowOnes--;
                end++; 
                start++;
                mnSwaps = min(mnSwaps,cntOnes-windowOnes );
            }
        }
        return mnSwaps;
    }
};
