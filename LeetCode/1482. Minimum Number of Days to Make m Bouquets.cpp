class Solution {
public:
    bool couldmake(vector<int>bloomDay , int m, int k , int day){
        long long count =0 ;
        long long bouquets =0 ;  
        for(int i =0 ; i < bloomDay.size() ; i++) {
            if(bloomDay[i] <= day){
                count++;
            }else{
                if(count >= k ) {
                    bouquets+=(count/(long long)k); 
                }
                count=0; 
            }
        }
        bouquets+=(count/(long long)k); 
        return (bouquets>= m );
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        if( ((long long )m*k) > bloomDay.size()) return -1 ; 
        long long  end = *max_element(bloomDay.begin() , bloomDay.end());
        long long start = *min_element(bloomDay.begin() , bloomDay.end()); 
        long long ans =0 ;
        while(start <= end ){
            long long  mid = (start+ end) /2; 
            if(couldmake(bloomDay , m, k , mid  )) {
                end = mid -1;
                ans = mid;   
            }else {
                start = mid+1 ; 
            }

        }

        return ans;
    }
};
