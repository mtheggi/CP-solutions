class Solution {
public:
    int solve(string s, int indx , string& s_ , string target, vector<vector<int>>&dp ) {
        if(s_ == target) return 1 ;  
        if(indx >= s.size() ) return 0; 
        if(!target.starts_with(s_)) return 0; 

        if(dp[indx][s_.size()] != -1 ) return dp[indx][s_.size()]; 
        
        s_.push_back(s[indx]);  
        int optiona = solve(s , indx+1 , s_ , target , dp ); 
        s_.pop_back();  
        int optionb = solve(s , indx+1 , s_ , target , dp ) ; 
        
        return dp[indx][s_.size()]=  optiona + optionb; 
    }


    int numDistinct(string s, string t) {
        string s_ = ""; 
        vector<vector<int>> dp(s.size()+2 , vector<int> (s.size() +2 , -1 ) ); 
        return solve(s  , 0 , s_ , t , dp ); 
    }
};
