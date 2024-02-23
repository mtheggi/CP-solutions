
/*super missy solution ... but still working */
class Solution {
public:
    string longestPalindrome(string s) {
            vector<vector<bool>> isPal(s.size()+2 , vector<bool>(s.size()+2 , false )); 
            for(int i =0 ;i < s.size() ; i++) isPal[i][i]= true; 

            for(int i =0 ;i  < s.size() ; i++) {
                int left = i ; 
                int right = i;
                while(right<s.size() && s[left]==s[right+1]) {
                    isPal[left][right+1] = true; 
                    right++; 
                }
                while(s[left]==s[right] && isPal[left][right] ) {
                    if((left-1)>=0 && (right+1)< s.size()){
                        isPal[left-1][right+1] = (s[left-1]==s[right+1] && isPal[left][right]);
                        if(isPal[left-1][right+1]) {
                            left--;
                            right++; 
                        } else
                            break;  
                    }else{
                        break; 
                    }
                }
              
            }
            int len = -1 ; 
            int l ;
            for(int i =0 ;i < s.size() ; i++) 
                for(int j =0 ; j < s.size() ; j++) {
                    if((j-i) > len && isPal[i][j]){
                        len=j-i; 
                        l=i;
                    }
                }

        return s.substr(l , len+1); 
    }
};
