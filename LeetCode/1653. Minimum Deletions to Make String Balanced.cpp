class Solution {
public:
    int minimumDeletions(string s) {
        vector<int>suffixA(s.size()+1 , 0 ),prefixB(s.size()+1 , 0 );
        for(int i =0 ;i < s.size() ; i++) {
            if(s[i] =='a')suffixA[i] =1; else prefixB[i]=1; 
            if(i>0)prefixB[i]+=prefixB[i-1]; 
        }
        for(int i =s.size()-2 ;i >=0  ; i--) suffixA[i]+=suffixA[i+1]; 
        int ans =INT_MAX; 
        for(int i =0 ;i<s.size() ; i++) {
            ans = min(suffixA[i]+prefixB[i] -(s[i]=='a'), ans); 
        }
        ans=min({ans, suffixA[0],  prefixB[s.size()-1]});
        return ans; 
    }
};
