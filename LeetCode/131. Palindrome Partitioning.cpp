class Solution {
public:
    bool is_palindrom( string x ) {
        string y =x;  
        reverse(x.begin() , x.end()); 
        return x == y; 
    }

    void _partition(vector<vector<string>> & ans , string s , int indx , vector<string>& part ) {
        string concat = ""; 
        for(int i  =0 ; i < part.size(); i++) {
            if(!is_palindrom(part[i])) {
                return; 
            }
            concat+=part[i]; 
        }
        if(concat == s ) {
            ans.push_back(part); 
            return; 
        }

        for(int i = indx ; i < s.size() ; i++){
            string substr = s.substr(indx, i-indx + 1) ; 
            part.push_back(substr); 
            _partition(ans , s , i+1 , part); 
            part.pop_back(); 
        }
        return; 
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;  
        int indx =0 ; 
        vector<string> part ; 
        _partition(ans , s , indx , part ); 
        return ans;  

    }
};
