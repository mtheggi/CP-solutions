class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        priority_queue<pair<long long , int >> pq ; 
        vector<int>nums(n,  0); 
        sort(meetings.begin() , meetings.end());
        for(int i =0 ; i<n ;  i++)  pq.push({1e6 , -i}); 

        for(int i =0 ;i < meetings.size() ; i++){
            long long  diff = meetings[i][1] - meetings[i][0];  
            priority_queue<pair<long long  ,int >> pq2 ; 
            while(pq.size()){
                pair<long long  ,int > r = pq.top(); 
                if(-1*r.first <= meetings[i][0]) r.first= 1e6; 
                pq.pop(); 
                pq2.push(r); 
            }
            pq = pq2 ; 
            pair<long long  ,int > room = pq.top(); 
            if(room.first == 1e6 ) {
                room.first = -1* meetings[i][1]; 
                nums[-1 * room.second]++; 
            }else {
                room.first= min(room.first - diff,-1ll* meetings[i][1]);  
                nums[-1* room.second]++; 
            }
            pq.pop(); 
            pq.push(room); 
        }
        int mxIndx = -1  , mx = -1 ; 
        for(int i =0 ;i < n ; i++) {
            if(nums[i] > mx ) {
                mx = nums[i]; 
                mxIndx =i ;    
            }
        }
        return mxIndx;

    }
};
