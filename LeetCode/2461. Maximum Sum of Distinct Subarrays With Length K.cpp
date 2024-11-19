class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans =0 ,currSum =0;
        int n = nums.size(),  unique=0, released , taken,WindStart=0, WindEnd = k-1; 
        unordered_map<int,int>currList;
        for(int i = WindStart ; i <= WindEnd; i++) {
            if(currList[nums[i]] == 0 ) unique++; 
            currSum+=nums[i]; 
            currList[nums[i]]++; 
        }
        if(unique == k) ans=currSum;
        while(WindEnd+1 < n ){
            released= nums[WindStart++]; 
            taken  = nums[++WindEnd];
            if(taken == released) continue;
            if(currList[taken]==0) unique++; 
            if(currList[released]== 1) unique--; 
            currList[taken]++;
            currList[released]--;
            currSum = currSum-released+taken;
            if(unique==k)
                ans = max(ans, currSum); 
        }
        return ans;
    }
};
