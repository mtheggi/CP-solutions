class Solution {
public:
    int maxProduct(vector<int>& nums) {
           
        int mn =1,mx =1, sol=INT_MIN; 
        for (auto i : nums ) {
            int mntemp =mn*i; 
            mn = min(i, min(mn*i,mx*i)); 
            mx= max(i,max(mntemp  , mx*i)); 
            sol=max(sol, mx ); 
        }

        return sol; 
    }
};
