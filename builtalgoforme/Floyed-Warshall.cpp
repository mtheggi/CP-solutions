#include<bits/stdc++.h>
using namespace std ;
// O(n^3) 
// Advantages : 1- easier implementation than dijkstra 
                // 2- works with both directed and undirected graph  
                // 3- works with negative weights  
                // 4- check negative cycles by checking if any diagonal entry in the distance matrix is negative.
            // 5- Algorithm logic could be used in problem with special requirment
                // for example : if you want the shortes path that path across certain nodes 
                    // you can change K value as each iteration adds one or more nodes between src and destination 
                // 6- can be used in qurey problems 
void Floyed(vector<vector<long long >> &dp_APSP , int nodes ) { // dp_APSP --> Graph Matrix to calc "all pair shortest path"
    for(int k =1 ; k <= nodes ; k++)
        for(int i = 1 ; i <=nodes ; i++)
            for(int j = 1 ; j<=nodes ; j++)
                dp_APSP[i][j] = min(dp_APSP[i][k]+ dp_APSP[k][j] , dp_APSP[i][j]);
}

int main() {
 
    int n, m ;
    cin >> n >> m ;
    vector<vector<long long >> dist(n+2, vector<long long >(n+2 ,1e17));

    for(int i =1;i <= n ; i++) dist[i][i] = 0;

    for(int i =0 ;i < m ;i++) {
        int u , v, w ;
        cin >> u >> v >> w;
        dist[u][v] = w;
        dist[v][u] =w ; // if undirected
    }

    Floyed(dist, n );

 
}