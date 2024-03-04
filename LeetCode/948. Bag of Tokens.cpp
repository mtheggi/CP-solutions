class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        // playing
        // faceup  
        // 1- if(power>= tokens[i]) {
            // may play 
            //power-=token[i] ; 
            // score++; 
        //}
        // face down    

        // 2- if(score > 0 ) {
            //score--; 
            // power+=tokens[i];
        //}
        // 200 , 0  
        // 100 sore =1 (played 100) ;  
        // 500 score = 0 ; 
        // socor  2 
        deque<int> dq ; 
        int mx = 0; 
        sort(tokens.begin() , tokens.end()); 
        for (auto tkn  : tokens ) dq.push_back(tkn); 
        int score= 0 ;
        bool canTake = true;  
        while(dq.size() && canTake) {
            if(power>= dq.front()) {
                score++; 
                power-=dq.front(); 
                dq.pop_front(); 
                mx= max(mx , score ); 
            }else if(score > 0 ) {
                power+=dq.back(); 
                score--; 
                dq.pop_back(); 
            }else{
                canTake=false ;
            }
        }
        return mx;
    }
};
