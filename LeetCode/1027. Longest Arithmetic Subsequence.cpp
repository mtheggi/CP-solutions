class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size() ; 
        vector<vector<vector<int>>>dpInc(2, vector<int>(502, vector<int>(nums.size()+2,1)));
        int ans = 1;
        unordered_map<int,int> diffInc, diffDec;             
        for(int i= 0; i<=500 ;i++) {
            diffInc.clear(); 
            diffDec.clear(); 
            for(int j =0;j < n ;j++) {
                if(diffInc.find(nums[j]-i) != diffInc.end()){
                    dpInc[0][i][j]=max(dpInc[0][i][j] , dpInc[0][i][diffInc[nums[j]-i]] +1);
                    ans = max(ans, dpInc[0][i][j]); 
                }
                if(diffDec.find(nums[j]+i) != diffDec.end() ){
                    dpInc[1][i][j]=max(dpInc[1][i][j] , dpDec[i][diffDec[nums[j]+i]] +1);
                    ans = max(ans, dpDec[i][j]); 
                }
                diffDec[nums[j]] =j;
                diffInc[nums[j]] =j;
            }
        }   
        return ans;  
    }
};
