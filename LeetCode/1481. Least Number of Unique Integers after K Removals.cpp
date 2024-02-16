class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int ,int > freq ;
        vector<pair<int ,int >> freq_el ;
        for(int i =0 ;i < arr.size() ; i++) {
            freq[arr[i]]++; 
        }
        for(auto i  : freq) {
            freq_el.push_back({i.second , i.first}); 
        }
        sort(freq_el.begin() , freq_el.end()); 
        int size = freq_el.size(); 
        int indx =0; 
        for( indx =0 ; indx < freq_el.size() ; indx++) {
            if(k< freq_el[indx].first){
                break; 
            }else {
                k-=freq_el[indx].first;
            }
        }
        return size-indx;
   
    }
};
