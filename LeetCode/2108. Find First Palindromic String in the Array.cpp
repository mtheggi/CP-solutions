class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for (int i =0 ;i < words.size() ; i++) {
            string x = words[i]; 
            reverse(x.begin() , x.end()); 
            if(x == words[i]){
                return words[i];
            }
        }
        return ""; 
    }
};
