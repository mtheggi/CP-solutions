#include <bits/stdc++.h>
//
using namespace std;
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
    vector<unsigned int> dp(target +3 , 0 ) ;
    dp[0] = 1;
    for(int x = 1; x <= target ; x++) {
        for(int i=0;i< (int)nums.size() ; i++) {
              if( x - nums[i]  >= 0 )
                  dp[x] += dp[x - nums[i]];  

        }
    }
    return dp[target];
}



};