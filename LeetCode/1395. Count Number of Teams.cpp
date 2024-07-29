class Solution {
public:

    int numOfincreasingSeq(vector<int> & rating, bool isInc){
        vector<vector<int>> dp (4, vector<int>(rating.size()  ,0)); 
        // dp[k][i] --> number of increasing/decreasing seq of length k ending with index i; 
        
        for(int i =0 ;i < rating.size() ; i++) dp[1][i]=1;
        int ans=0; 
        for(int k = 2; k<=3; k++) {
            for(int j=(k-1) ; j< rating.size() ; j++) {
                for(int i=(k-2); i<j; i++){
                    if(isInc && rating[j] > rating[i]) dp[k][j]+=dp[k-1][i]; 
                    if(!isInc && rating[j] < rating[i] ) dp[k][j]+=dp[k-1][i];;
                }
                if(k==3 ) ans+=dp[3][j]; 
            }
        } 
        return ans; 
    }

    int numTeams(vector<int>& rating) {
        return numOfincreasingSeq(rating, true ) + numOfincreasingSeq(rating, false );    
    }
};
