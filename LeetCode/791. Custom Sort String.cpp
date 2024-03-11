class Solution {
public:
    string customSortString(string order, string s) {

        map<char,  int>  chr_indx; 
        for(int i =0 ;i < order.size() ; i++) chr_indx[order[i]]= i;  
        sort(s.begin(),  s.end() , [&chr_indx](const char & x , const char &y ) -> bool {
            if(chr_indx[x] < chr_indx[y]) return true ; 
            else return false;  
        });
        return s ;
    }
};
