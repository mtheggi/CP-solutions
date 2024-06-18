class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        long long ans =0 ; 
        
        vector<pair<int ,int >> vec  ; 
        vector<int> prefix_max(profit.size()+1 );
        
        for(int i =0 ;i < difficulty.size(); i++) vec.push_back({ difficulty[i], profit[i] }); 
        
        sort(vec.begin() , vec.end()); 

        prefix_max[0] = vec[0].second;  
        
        for(int i =1;i < vec.size() ; i++) prefix_max[i] = max(prefix_max[i-1] , vec[i].second ); 
        for(auto ability : worker ){
            auto firstLarge =upper_bound(vec.begin() , vec.end() , make_pair(ability , INT_MAX));
            if(firstLarge == vec.begin()) continue;
            ans+= prefix_max[firstLarge - vec.begin()-1]; 
        }
        return ans; 
    }
};
