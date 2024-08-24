// do not follow this code , it is a super random bad way to solve the problem  XD 
class Solution {
    bool tenth(string n ) {    
        int cnt0=0; 
        for(int i = 0 ; i< n.size() ; i++){
            if(n[i] == '0') cnt0++; 
        }
        if(n[0]=='1' && cnt0 == n.size()-1) return true; 
        else return false ; 
    }
    bool all9(string n ) {    
        int cnt9=0; 
        for(int i = 0 ; i< n.size() ; i++){
            if(n[i] == '9') cnt9++; 
        }
        if(cnt9 == n.size()) return true; 
        else return false ; 
    }
    bool ispalind(string n) {
        string ans=n; 
        reverse(ans.begin(), ans.end()); 
        return ans==n; 
    }

public:
    
    string nearestPalindromic(string n) {
        int size =n.size(); 
        if(size==1){
            if(n == "0") return "1"; 
            else{ n[0] = n[0]-1 ; return n; }
        }else if(tenth(n)){
            string ans(n.size()-1 , '9'); 
            return ans; 
        }else if(all9(n)){
            string ans(n.size()+1 , '0'); 
            ans[0]='1'; 
            ans[ans.size()-1] ='1'; 
            return ans;
        }       
        int mid=size/2-1; 
        char before = n[0]=='1' ? '9' :n[0]-1;  
        string ans1,  ans2 , ans3 ,ans4(size-1, before) ; 
        string first= n.substr(0, mid+1);
        string firstinc = first , firstdec = first;  
        string last= first, lastinc=firstinc , lastdec=firstdec; 
    
        if(size%2){
            reverse(last.begin(),last.end()); 
            reverse(lastinc.begin(),lastinc.end()); 
            reverse(lastdec.begin(),lastdec.end()); 
            first.push_back(n[mid+1]); 
            firstinc.push_back(n[mid+1]); 
            firstdec.push_back(n[mid+1]);
            long int org = stol(first); 
            firstinc = to_string(org+1); 
            firstdec= to_string(org-1); 
        }else {
            long int org = stol(first); 
            firstinc = to_string(org+1); 
            firstdec= to_string(org-1); 
            
            last=first , lastinc=firstinc,lastdec=firstdec; 
            reverse(last.begin(),last.end()); 
            reverse(lastinc.begin(),lastinc.end()); 
            reverse(lastdec.begin(),lastdec.end()); 
           
        }
        ans1=first+last; 
        if(size==2) {
            ans2=firstinc+firstinc; 
            ans3=firstdec+firstdec;
        }else {
            ans2=firstinc+lastinc; 
            ans3=firstdec+lastdec;
        }     
        
        long int original = stol(n); 
        vector<pair<long int , string>> v; 
        v.push_back({stol(ans1),ans1}) ;
        v.push_back({stol(ans2),ans2}) ;
        v.push_back({stol(ans3),ans3}) ;
        v.push_back({stol(ans4),ans4}) ;
        sort(v.begin(), v.end()); 

        long int diff1 = abs(original-v[0].first); 
        long int diff2 = abs(original-v[1].first);         
        long int diff3 = abs(original-v[2].first);         
        long int diff4 = abs(original-v[3].first);


        if(diff1 ==0  || !ispalind(v[0].second)) diff1=INT_MAX; 
        if(diff2 ==0 ||!ispalind(v[1].second)) diff2=INT_MAX; 
        if(diff3 ==0 ||!ispalind(v[2].second)) diff3=INT_MAX; 
        if(diff4 ==0 ||!ispalind(v[3].second)) diff4=INT_MAX; 
        if(diff1 == min({diff1, diff2, diff3, diff4}) ) return v[0].second; 
        else if(diff2 == min({diff1, diff2, diff3 , diff4})) return v[1].second; 
        else if(diff3 == min({diff1, diff2, diff3 , diff4})) return v[2].second; 
        else return v[3].second; 
    }
};

