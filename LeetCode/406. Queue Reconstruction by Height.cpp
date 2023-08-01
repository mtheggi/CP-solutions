// Source : https://leetcode.com/problems/queue-reconstruction-by-height/
// Author : Mohamed Heggi 
// Date   : 27 - 5 - 2022



bool cmp(const vector<int> & v1 , const vector<int>& v2){
        if(v1[0] == v2[0]  && v1[1] <= v2[1])
            return true ;
        else if(v1[0] < v2[0]) 
            return true;
        else 
            return false; 
}    
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), cmp);
        vector<vector<int>> Result(people.size(), vector<int>(2,-1) );
        int Cnt;
        int h ; 
        int N = people.size(); 
        for(auto person : people){
            h = person[0]; 
            Cnt = person[1];
            int pos = 0;
            while(Cnt> 0 || Result[pos][1]!=-1 ){
                if( Result[pos][0] == -1 ||Result[pos][0] >= h ) {
                    Cnt--;   
                }
                 pos++;        
            }
            Result[pos]=person; 
            
        }
    
        
    
    return Result ; 
    }
};