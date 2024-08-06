class Solution {
public:
    int minimumPushes(string word) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        vector<int> pad(8 , 0 ); 
        vector<int> freq(27 , 0 ); int ans =0;
        for(auto &c : word ) freq[c-'a']++; 
        sort(freq.begin() , freq.end() , greater<int>()); 
        for(int i =0; i< 26 ; i++) {
            pad[i%8]++;
            ans+=(pad[i%8]*(freq[i])); 
        }
        return ans;
    }
};
