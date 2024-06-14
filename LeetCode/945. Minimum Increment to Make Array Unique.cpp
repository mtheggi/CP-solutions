class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        map<int , bool > exists;
        sort(nums.begin() , nums.end()); 
        int ans =0 ; 
        int prev= nums[0]; 
        exists[prev] = true; 
        for(int i =1 ;i < nums.size() ; i++) {
            int number = nums[i]; 
            if(exists[number]){
                int newNumber = prev +1 ; 
                ans+=(newNumber-number); 
                exists[newNumber]= true; 
                prev= newNumber; 
            }else {
                exists[number]= true; 
                prev=number; 
            }
        }  
        return ans; 
    }
};
