class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        set<vector<int>> set;
        vector<vector<int>> output;
        for(int i=0; i<n-3; i++){
            for(int j=i+1; j<n-2; j++){
                int st = j+1, end = n-1 ; 
                long long  newTarget = (long long )target - (long long )nums[i]- (long long ) nums[j]; 
                while(st< end ) {
                    if(nums[st]+nums[end] < newTarget) {
                        st++; 
                    }else if ((long long )nums[st]+(long long )nums[end] > newTarget ) {
                        end--; 
                    }else   {
                        set.insert({nums[i], nums[j], nums[st], nums[end]});
                        st++; 
                        end--;
                    }
                }   
                
            }
        }
        for(auto it : set){
            output.push_back(it);
        }
        return output;
    }
};
