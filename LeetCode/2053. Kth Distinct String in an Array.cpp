class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string , int > freq ; 
        for(int i =0 ; i < arr.size() ; i++ ) { freq[arr[i]]++; } 
        int kths =0 ; 
        for(int i =0 ;i < arr.size() ; i++) {
            if(freq[arr[i]] == 1 ) kths++;
            if (kths == k ) return arr[i];  
        }
        return ""; 

    }
};
