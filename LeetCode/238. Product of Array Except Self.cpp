class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size() ; 
        vector<int> prefix(size+2 ), suffix(size+2 ) , ans(nums.size()) ; 
        int last = size -2 ;
        prefix[0]=nums[0]; 
        suffix[size-1] = nums[size-1];          
        
        for(int i =1 ;i < size; i++) {
            prefix[i] = prefix[i-1]*nums[i]; 
            suffix[last] = suffix[last+1]*nums[last];
            last--; 
            
        }
        for(int i= 0; i<size ; i++) {
            int before = i!=0 ? prefix[i-1] : 1 ; 
            int after = i!=(size-1) ? suffix[i+1] : 1  ; 
            ans[i] = before * after ;  
        }
        return ans; 


    }
};
