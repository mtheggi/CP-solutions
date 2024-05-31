class Solution {
public:
    int findMin(vector<int>& nums) {
        int first = nums[0] ;
        int last =  nums[nums.size()-1];
        int  start =0  , end = nums.size()-1 ;
        int mid , ans= INT_MAX ; 
        while(start<=end) {
            mid = (start+end)/2 ; 

        
            if(mid > 0 && mid+1< nums.size() &&  nums[mid] < nums[mid-1] && nums[mid] < nums[mid+1]){
                ans = nums[mid] ;
                break;  
            }
            if(nums[mid] < last ) {
                end = mid -1;  
            }else {
                start = mid +1 ; 
            }
        }
        return min(first , min(last , ans ));

    }
};
