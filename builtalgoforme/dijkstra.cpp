// dijkstra 

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
#include <limits>

using namespace std;

typedef pair<int, int> P;


int main() {
    int n ,m , w , u, v   ; 
    cin >> n >> m ; 
    vector<vector<pair<int ,int>>> graph(n+2) ; 
    for(int i =0 ;i < m ; i++) {
        cin >> u  >> v  >> w;  
        graph[u].push_back({v , w}) ; 
        graph[v].push_back({u , w}) ; 
    }
}