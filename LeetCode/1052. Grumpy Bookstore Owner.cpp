class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size() ; 
        int mx = -1 ,l ,r ; 
        int ans =0 ; 
        
        vector<int> test(customers.begin() , customers.end() );
        
        for(int i =0 ; i < n ;i++) 
            if(grumpy[i] == 0 ) 
                test[i]=0;
            
        for(int i =1 ;i <n ; i++ ) test[i]+=test[i-1]; 
        
        for(int i =0 ;i <=n-minutes ; i++) {
            int temp = mx ; 
            int prev = i==0 ? 0 : test[i-1];
            mx = max(mx , test[i+ minutes-1 ]- prev); 
            if( mx != temp ){
                l = (i==0) ? 0 : i; 
                r = i+ minutes-1; 
            }
        }

        for(int i =0 ; i < n ; i++) 
            if(grumpy[i] == 0 || (i>=l && i<=r)  ) ans+=customers[i]; 
            
        

        return ans ; 

    }
};
