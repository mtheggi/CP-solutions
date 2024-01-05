class Solution {
public:
  void sol(int indx , vector<vector<int>> &ans , vector<int> &combination , vector<int>&candidates , int target ) {
    if(target<0) {return;}
    if(target == 0) {ans.push_back(combination) ; return;  }

    for(int i =indx ;i < candidates.size() ; i++) {
             if(i>indx && candidates[i]==candidates[i-1]){continue;}

            combination.push_back(candidates[i]);
            sol(i+1,ans ,combination ,  candidates , target-candidates[i]);
            combination.pop_back();
        
    }

}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin() , candidates.end());
    vector<vector<int>> ans;
    vector<int> comb;
    sol(0, ans, comb , candidates, target);     
    return ans;
}
};
