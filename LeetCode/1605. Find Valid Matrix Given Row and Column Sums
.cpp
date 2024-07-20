class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
         vector<vector<int >> ans(rowSum.size() , vector<int>(colSum.size(), 0 ));
    long long currColSum =0;
    for(int i =0 ; i < rowSum.size() ; i++) {
        ans[i][0] = rowSum[i];
        currColSum+=ans[i][0];
    }
    for(int i =0 ;i < colSum.size()-1 ; i++) {
        int target = colSum[i];
        long long toRemove = currColSum-target;
        currColSum =0;
        for(int j = 0 ; j < rowSum.size(); j++) {
            long long  remove = min(toRemove , (long long)ans[j][i]);
            ans[j][i]-=remove;

            ans[j][i+1]=remove;
            currColSum+=remove;
            toRemove-=remove;
        }
    }
    return ans;
    }
};
