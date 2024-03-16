class Solution {
    public:
        int maximalSquare(vector<vector<char>>& matrix) {
            int h = matrix.size() ; 
            int w = matrix[0].size() ; 
            vector<vector<int>> dp(h , vector<int>(w, 0)); 
            int ans =0; 
            for(int row =0 ; row < h ;  row++) 
                for(int col =0 ; col < w ; col++) {
                    if(row ==0 || col == 0 ) {
                        dp[row][col] = matrix[row][col]-'0';                
                        ans = max(ans , dp[row][col]);
                        continue;
                    }
                    if(matrix[row][col] == '1') {
                        dp[row][col] = min({dp[row-1][col] , dp[row-1][col-1] , dp[row][col-1]}) +1 ;
                        ans = max(ans , dp[row][col]);   
                    }
                }
            return ans*ans; 
        }
    };
