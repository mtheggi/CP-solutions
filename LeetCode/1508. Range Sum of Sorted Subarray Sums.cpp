class Solution {
    long long MOD; 
public:
    Solution():MOD(1e9+7){}
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<unsigned long long > sum;
        for(auto  &i : nums) sum.push_back(i); 
        vector<unsigned long long > Sums;
        for(int i =1 ; i < nums.size() ; i++) sum[i]+=sum[i-1]; 

        for(int i=0 ; i< nums.size() ; i++) {
            for(int j = i ; j< nums.size() ; j++){
                if(i!=0)
                    Sums.push_back(sum[j]-sum[i-1]);
                else 
                    Sums.push_back(sum[j]);   
            }             
        } 
        sort(Sums.begin(), Sums.end());
        left--; right--; 
        unsigned long long ans =0 ; 
        for(int i = left ; i<=right; i++) {
            ans = ((ans%MOD) + (Sums[i]%MOD))%MOD; 
        }   
        return ans; 
    }
};
