class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<long long >> graph(30,vector<long long >(30 , 2e12)); 
        for(int i =0 ;i < original.size() ; i++) {
            graph[original[i]-'a'][changed[i]-'a'] = min(graph[original[i]-'a'][changed[i]-'a'],(long long )cost[i]); 

        }   
        for(int j =0 ; j < 27 ; j++) graph[j][j] = 0; 
                
        for(int k =0 ; k < 27 ; k++) {
            for(int i =0 ; i < 27 ; i++) {
                for(int j =0 ; j < 27 ; j++) {
                    graph[i][j] = min(graph[i][k]+graph[k][j] , graph[i][j]); 
                }
            }
        }
        long long ans =0 ; 
        for(int i =0 ;i < source.size() ; i++) {
            if(graph[source[i]-'a'][target[i]-'a'] >= 2e12) return -1 ;  
            ans+=graph[source[i]-'a'][target[i]-'a']; 
        }
        return ans; 

    }
};
