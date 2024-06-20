class Solution {
public:
    bool isValid(vector<int> & position , int ans , int m ) {
        int count = 1 , prevBall= position[0]; 
        for(int i =1 ;i < position.size() ; i++) {
            if(position[i]-prevBall >=ans){
                count++; 
                prevBall= position[i]; 
            }
            if(count ==m){
                break; 
            }
        } 
        return (count==m);

    } 

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end()) ;
        int start =1 , end = position[position.size()-1] - position[0]; 
        int mid , ans  ; 
        while(start <= end ){
            mid = (start + end ) / 2; 
            if(isValid(position,mid,m)) {
                start = mid +1 ; 
                ans = mid ; 
            }else {
                end = mid -1 ; 
            }
        }
        return ans ; 
    }
};
