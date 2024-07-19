class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> ans; 
        for(int i =0 ;i < matrix.size(); i++) {
            auto ptr  = min_element(matrix[i].begin() , matrix[i].end()); 
            int index = ptr - matrix[i].begin() , mx = -1 ; 
            for(int j =0 ; j < matrix.size() ; j++) mx= max(mx , matrix[j][index]); 
            if(mx == *ptr ) ans.push_back(mx); 
        }   
        return ans; 
    }
};
