#include<bits/stdc++.h>
using namespace std;

// O(V+E);
void  BFS(int src ,vector<vector<int>> const & graph, vector<bool> & visited , vector<int> & parent , vector<int> &lvl) {
    parent[src] = -1;
    visited[src] =1 ;
    lvl[src] =0;
    queue<int> Q;
    Q.push(src) ;
    while(!Q.empty()){
        int front = Q.front();
        Q.pop() ;
        for(auto i : graph[front]){
            if(!visited[i]){
                Q.push(i);
                visited[i] = 1 ;
                lvl[i] = lvl[front] +1 ;
                parent[i] = front ;
            }
        }
    }
}

int main() {
    int nodes ,edges ;
    cin >> nodes >>  edges ;
    vector<vector<int>> graph(nodes+2);
    for(int i =0 ;i < edges ; i++){
        int u ,v ;
        cin >> u >> v;
        graph[u].push_back(v) ;
        graph[v].push_back(u); // if undirected ;
    }
    vector<int> level(nodes+2), parent(nodes+2);
    vector<bool> visited(nodes +2, 0 );
    BFS(0, graph ,visited, parent , level ); 
    

    return 0;
}