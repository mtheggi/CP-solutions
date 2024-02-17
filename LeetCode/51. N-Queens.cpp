class Solution { 
public:
    bool inboard(int i , int j , int n  ) {
        return (i>0 && i<n && j > 0 && j < n )  ; 
    }
                                                            
    bool _possible(int n,map<pair<int ,int >, bool > & queens, int row, int col){
        if(queens[{row , col }]) return false; 
        
        for(int i=0; i<n; i++){
            if( queens[{i, col}]){
                return false;
            }
        }
        for(int i=row-1, j=col-1; i>=0 && j>=0; i--, j--){
            if( queens[{i, j }]){
                return false;
            }
        }
        for(int i=row-1, j=col+1; i>=0 && j<n; i--, j++){
            if(queens[{i, j }] ){
                 return false;
            }
        }
        return true;
    }

    void _solveNQueen(int n , map<pair<int ,int >, bool> &queens , int row, int trueplacement  , vector<map<pair<int ,int >, bool>> &res ) {
        if(trueplacement == n ) {
            res.push_back(queens); 
            return ; 
        }


        for(int col = 0 ; col < n ; col++){
            if(_possible(n , queens ,row , col )){
                queens[{row , col }] = true; 
                _solveNQueen(n , queens, row+1, trueplacement +1 , res ) ;
                queens[{row, col}] = false; 
            }
        }
    }
  
    vector<vector<string>> solveNQueens(int n) {
        map<pair<int ,int > , bool > queens ;
        vector<map<pair<int ,int > , bool >> res;   
        _solveNQueen(n, queens , 0 , 0, res ); 
        vector<vector<string>> outz;  
  
        for(int z = 0 ; z<res.size(); z++) {
            queens = res[z]; 
            vector<string> out;  
            for(int i =0 ;i < n ; i++) {
                string x = ""; 
                for(int j =0 ; j<n ; j++) {
                    if(queens[{i , j }]) {
                        x.push_back('Q'); 
                    }else {
                        x.push_back('.');
                    }
                }
                out.push_back(x); 
            }
            outz.push_back(out); 
        }
        
        return outz ; 
    }
};
