class Solution {
    vector<string> unites; 
    vector<string> tenth; 
    vector<string> from11to19;  
public:
    Solution(){
        unites.resize(12); 
        tenth.resize(12); 
        from11to19.resize(12); 
        unites[1]="One"; 
        unites[2]="Two"; 
        unites[3]="Three"; 
        unites[4]="Four"; 
        unites[5]="Five"; 
        unites[6]="Six"; 
        unites[7]="Seven"; 
        unites[8]="Eight"; 
        unites[9]="Nine";
        tenth[2]="Twenty";
        tenth[2]="Twenty";
        tenth[3]="Thirty";
        tenth[4]="Forty";
        tenth[5]="Fifty";
        tenth[6]="Sixty";
        tenth[7]="Seventy";
        tenth[8]="Eighty";
        tenth[9]="Ninety";
        from11to19[0]="Ten";
        from11to19[1]="Eleven";
        from11to19[2]="Twelve";
        from11to19[3]="Thirteen";
        from11to19[4]="Fourteen";
        from11to19[5]="Fifteen";
        from11to19[6]="Sixteen";
        from11to19[7]="Seventeen";
        from11to19[8]="Eighteen";
        from11to19[9]="Nineteen"; 
    }
    string threeDigit(string str){
        int n  = str.size() ; 
        if(n ==0 ) return ""; 
        string ans ="";
        if(n==3){
            if(str[0]=='0') return threeDigit(str.substr(1,2)); 
            string before =threeDigit(str.substr(1,2));  
            string space = (before=="") ? "" : " "; 
            return( ans + unites[str[0]-'0']+ " Hundred" + space + before ) ; 
        }else if(n==2){
            if (str[0]=='0')return unites[str[1]-'0'];
            if(str[0]=='1')return from11to19[str[1]-'0'] ;
            else { if (str[1]-'0') return (tenth[str[0]-'0'] + " " + unites[str[1]-'0']); else return tenth[str[0]-'0']; }  
        }
        return unites[str[0]-'0'];
    }
    string calc(string str ){
        int size= str.size() ; 
        if(size == 0) return ""; 
        int rem = size%3; 
        if(rem == 0 ){
            int chuncks =size/3; 
            string ans ="" , middle="";
            if(chuncks == 1) return threeDigit(str); 
            if(chuncks==3) middle=" Million"; 
            else if(chuncks==2) middle =" Thousand"; 
            
            string before =calc(str.substr(3,size-3));  
            string space = (before=="") ? "" : " "; 
         
            string chstr =threeDigit(str.substr(0,3)); 
            if (chstr =="") middle =""; 
            
            ans+=(chstr + middle + space + before );  
            
            return ans ;


        }else {
            string middle= ""; 
            if(size>9) middle=" Billion"; 
            else if(size>6) middle =" Million"; 
            else if(size > 3) middle = " Thousand"; 
            string before =calc(str.substr(rem, size-rem));  
            string space = (before=="") ? "" : " "; 
         
            return threeDigit(str.substr(0,rem)) + middle +  space + before ; 
        }

    } 
    string numberToWords(int num) {
        if(num == 0 ) return "Zero";
        string num_str =""; 
        while(num) {
            num_str.push_back((num%10)+'0');
            num/=10; 
        }
        reverse(num_str.begin() , num_str.end()); 
        string shit =calc(num_str); 
        for(int i =0 ;i < shit.size()-1 ; i++) if(shit[i] == ' ' &&  shit[i+1] == ' ') {shit.erase(i ,1); i--;} 
        return shit;    
    }
};
