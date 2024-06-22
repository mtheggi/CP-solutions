class Solution {
public:
    int numberOfSubarrays(vector<int> nums, int k) {
    int left =0 , middle =0 , right =0 , countOdd =0 , ans=0 ; 

    while(right<nums.size() ) {
        if(nums[right]&1){
            countOdd++;
        }
        while(countOdd>k){
            if(nums[middle]&1){
                countOdd--;
            }
            middle++;
            left=middle;     
        }

        if(countOdd==k) {
            while(nums[middle]%2 ==0 ){
                middle++; 
            }
            ans+=(middle-left+1); 
        }
        
        right++; 
    }

    return ans;

    }
};
