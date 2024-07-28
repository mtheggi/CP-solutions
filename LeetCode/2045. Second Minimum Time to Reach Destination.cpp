class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> graph(n+2); 
        for(int i =0 ;i < edges.size() ; i++){
            graph[edges[i][0]].push_back(edges[i][1]); 
            graph[edges[i][1]].push_back(edges[i][0]);
        } 
        vector<int> dist1(n+2,INT_MAX) , dist2(n+2 , INT_MAX); 
        queue<pair<int, bool>> q; 
        q.push(make_pair(1, 0 )); 
        dist1[1]=0; 
        while(q.size()) {
            auto [node, isSecond] = q.front(); 
            q.pop(); 
            int currLevel = isSecond ? dist2[node]+1 : dist1[node]+1; 
            for(auto child : graph[node]){
                if(dist1[child] == INT_MAX) {
                    dist1[child] = currLevel;
                    q.push(make_pair(child,0 ));  
                }else if(dist2[child] == INT_MAX && currLevel != dist1[child]) {
                    dist2[child]=currLevel; 
                    q.push(make_pair(child,1));
                }
            }
        }
        long long TotalTime= 0; 
        for(int i =1; i <=dist2[n]; i++) {    
            if( (TotalTime/change)%2 != 0){
                TotalTime+=( (TotalTime/change +1)*change - TotalTime); 
            }
            TotalTime+=time; 
        }

    return TotalTime; 

    }
};
