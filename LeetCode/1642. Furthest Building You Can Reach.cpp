class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int indx =0 ;         
        priority_queue<int>pq ; 

        for( indx =0 ; indx< heights.size()-1 ; indx++) {
            int diff = heights[indx+1] - heights[indx]; 
            if(diff > 0 ){
                if(bricks-diff < 0 ) {
                    bricks-=diff; 
                    pq.push(diff); 
                    int max_diff= pq.top();
                    pq.pop();
                    bricks+=max_diff; 
                    ladders--;  
                    if(ladders<0) break;

                    
                }else {
                    bricks-=diff;
                    pq.push(diff);
                }

            }                  
        }      
        return indx; 
    }
};
