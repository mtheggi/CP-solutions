// Find the strongly connected compnents in the Graph ; 
/*
    For Undirected component , you should find the number of component as the number of component is equal to the number of Strongly connected component 
*/
#include<bits/stdc++.h>

using namespace std;

int const N = 1e3 +2 ;
vector<vector<int>> graph(N+2 ) ;
vector<vector<int>> reversed_graph(N+2 ) ;
int n , m ;

void FirstDFS(int src , vector<bool> & visited , stack<int>& stackOfnodes) {
    visited[src] =1 ;
    for(auto child : graph[src]){
        if(!visited[child]){
            FirstDFS(child , visited , stackOfnodes);
        }
    }
    stackOfnodes.push(src);
}
void SecondDFS(int src,  vector<bool>& visited){
    cout << src << " " ;
    visited[src] =1;
    for(auto child  : reversed_graph[src]){
        if(!visited[child])
            SecondDFS(child , visited) ;
    }
}

void kosaraju_SCC() {
    stack<int> stackOfnodes ;
    vector<bool> visited(N , 0 )  ;
    for(int i = 1 ;i <= n ; i++){
        if(!visited[i])
            FirstDFS(i , visited ,stackOfnodes) ;
    }

    fill(visited.begin(), visited.end(),0 );
    while(!stackOfnodes.empty()){
        int top = stackOfnodes.top() ;
        stackOfnodes.pop();
        if(!visited[top]){
            SecondDFS(top, visited);
            cout << "\n" ;
        }


    }
}

int main() {
    cin >> n >> m ;
    for(int i =0 ;i < m ;i++) {
        int u , v;
        cin >> u >> v;
        graph[u].push_back(v) ;
        reversed_graph[v].push_back(u);
    }
    //  kosaraju steps ;
    // 1- DFS and push values in the stack ;
    // 2- reversed the graph
     // 3- DFS on reversed graph on the order of the stack top  : output the visited nodes ;
    kosaraju_SCC();

    return 0;
}