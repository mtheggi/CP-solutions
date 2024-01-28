class Solution {
    map<int ,string > digitsMap ; 
public:
    Solution() {
        char startch = 'a'; 
        for (int i =2 ; i<=9 ; i++){
            int limit = (i==7||i==9)? 4: 3 ;
            string conc = "";  
            for (int j =0 ; j < limit ; j++ ){
                conc.push_back(startch); 
                startch++; 
            }
            digitsMap[i]= conc; 
        }
    }
    
    void _letterCombinations(string digits , vector<string> &ans , string &combination , int Indx){
       
        if(combination.size() == digits.size() ) {    
            ans.push_back(combination); 
            return ;
        }
        if(Indx >= digits.size() ) 
            return; 

        int num= digits[Indx]-'0';
        for(int i = 0 ; i< digitsMap[num].size() ; i++) {
            combination.push_back(digitsMap[num][i]); 
            _letterCombinations(digits , ans , combination , Indx +1 ); 
            combination.pop_back(); 
        }
        return; 


    }

    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0 ) return {}; 

        vector<string> ans; string combination = ""; 
        int Indx =0 ; 
        _letterCombinations(digits , ans , combination , Indx);  
      return ans; 
    }
};
