class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size(); 
        vector<int> dp(books.size()+2,0);
        // dp[i] minimal height to arrange from 1 to i books 
        for(int i = 1;  i<=n ; i++) {
            int currentWidth =  books[i-1][0]; 
            int currentHeight = books[i-1][1]; 
            dp[i] = dp[i-1] +currentHeight; // start by assuming by putting the book on the new shelf .
            // after that start to go from back to front trying to append previous books until you append more books (because of shelfWidth)
            // make that until you reach the book which you can not append ; 
            // take the optimal height at the book (which will be calculated in dp array ) and add the max height of the books on the last made shelf ; 
            for(int j = i-2 ; j >= 0 ; j-- ) {
                if(currentWidth + books[j][0] <= shelfWidth){
                    currentWidth+=books[j][0]; 
                    currentHeight= max(books[j][1] ,currentHeight); 
                    dp[i] = min(dp[i] , dp[j]+currentHeight); 
                }else break; 
            } 
        }

        return dp[n]; 

    }
};
