class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        sort(s.rbegin() , s.rend() ); 
        auto indx = find(s.begin() , s.end() , '0');
        if(indx == s.end() || indx == s.begin() ) return s;  
        int indxnum = indx-s.begin(); 
        s[indxnum-1]='0';
        s[s.size()-1] ='1' ; 
        return s; 

        
    }
};
