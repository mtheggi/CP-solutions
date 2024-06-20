class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(target == nums[0]) return 0; 
        if(target == nums[nums.size()-1 ]) return nums.size()-1; 
        int start =0 , end = nums.size()-1, mid ; 
        int lowest = nums[0] < nums[nums.size()-1] ? 0 : nums.size()-1;   
        while(start<=end) {
            mid = (start + end) /2;
            if(mid-1 >=0 && mid+1 < nums.size() && nums[mid]<nums[mid-1] && nums[mid] < nums[mid] +1 ){ lowest = mid; break;}   
            if(nums[mid] > nums[nums.size()-1] ){
                start = mid+1 ;
            }else {
                end = mid-1; 
            }
        } 
        if(nums[lowest] == target) return lowest;  
        start = target > nums[nums.size()-1] ? 0 : lowest; 
        end  = target > nums[nums.size()-1 ] ? lowest-1 : nums.size()-1 ; 
        while(start <=end ) {
            mid = (start + end ) /2 ; 
            if(nums[mid]==target ) return mid ;
            if(nums[mid] > target ) {
                end = mid -1; 
            }else{
                start = mid+1; 
            }
        }
  
        return -1; 
    }
};
