class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(trust.size() == 0 ){
            if(n == 1 ){
                return 1; 
            }else 
            return -1 ; 
        }
        map<int ,int > trusts ; 
        for(int i =0 ; i < trust.size(); i++){
            trusts[trust[i][0]]--; 
            trusts[trust[i][1]]++; 
        }
        for(auto i : trusts ) {
            if(i.second == (n-1)){
                return i.first ; 
            }
        }
        return -1 ; 
    }
};
