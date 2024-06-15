class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int ,int >> caps; 
    
        for(int i =0 ;i < profits.size() ; i++) caps.push_back ({capital[i] , profits[i]});
    
        sort(caps.begin(), caps.end()); 
    
        priority_queue<int> pq;
        int last=0 ; 
    
        for(int i =0  ;i < k ; i++) {
            int indx = last ;
            while(w>=caps[indx].first && indx<caps.size() ){
                pq.push(caps[indx].second); 
                indx++; 
            }
            last=indx;         
            if(pq.size() ==0 ) break; 
            w+=pq.top() ; 
            pq.pop(); 
       }

      return w ;
    }
};
