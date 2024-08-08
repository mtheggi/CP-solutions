class Solution {
public:

    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<pair<int ,int >> directions = {{0 ,1 } , {1,0} , {0 , -1 } , {-1 , 0 }} ; 
        // Left , Down ,right , UP ; 
        vector<vector<int>> ans; 
        int curRow = rStart , curCol=cStart; 
        int steps= 1 ; 
        int i=0;
        while(ans.size() < (rows*cols) ){
            for(int x = 0 ; x<2 ; x++){
                int dx = directions[i].first , dy=directions[i].second; 
                for(int i =0 ;i < steps;  i++ ){
                    if(curRow<rows && curRow>=0 && curCol >=0 && curCol<cols) ans.push_back({curRow, curCol}); 
                
                    curRow+=dx; 
                    curCol+=dy;
                }
                i=((i+1)%4); 
            }
            steps+=1; 
        } 
        return ans; 
    }
};
