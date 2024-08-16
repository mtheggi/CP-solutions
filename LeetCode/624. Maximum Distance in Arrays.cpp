class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        vector<pair<int ,int >> mxs, mns ;
        
        for(int i =0 ;i < arrays.size(); i++) {
          mxs.push_back({arrays[i][arrays[i].size()-1] , i });
          mns.push_back({arrays[i][0] , i }); 
        }

        sort(mns.begin(), mns.end()); 
        sort(mxs.begin(), mxs.end() , greater<pair<int ,int >>() );

        return (mxs[0].second == mns[0].second ) ? 
        max(abs(mxs[1].first - mns[0].first ) , abs(mxs[0].first - mns[1].first )) :
        abs(mxs[0].first - mns[0].first ) ;  
    }
};
