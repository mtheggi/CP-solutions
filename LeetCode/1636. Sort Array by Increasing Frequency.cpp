class Solution {
public:
    static bool cmp(pair<int ,int > a,  pair<int ,int > b ) {
        if(a.first < b.first )return true; 
        else if(a.first > b.first) {
            return false; 
        }else {
            if(a.second>b.second ) return true; 
            else return false; 
        }
    }
    vector<int> frequencySort(vector<int>& nums) {
        map<int , int > freq; 
        vector<pair<int ,int >> el_freq; 
        for(auto & i : nums ) freq[i]++;
        for(auto  i : freq) {
            el_freq.push_back(make_pair(i.second , i.first )); 
        }
        sort(el_freq.begin() , el_freq.end() , this->cmp ); 
        vector<int> ans; 
        for(auto i : el_freq) {
            int test = i.first; 
            while(test--) ans.push_back(i.second ); 
        }
        return ans; 
        
    }
};
