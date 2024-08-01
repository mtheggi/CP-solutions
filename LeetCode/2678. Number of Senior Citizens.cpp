class Solution {
public:
    int countSeniors(vector<string>& details) {
        int cnt =0 ; 
        for(auto & det : details ) if(int age = (det[11]-'0')*10 + (det[12]-'0'); age > 60 ) cnt++;  
        return cnt; 
    }
};
