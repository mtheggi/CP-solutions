#include<bits/stdc++.h>
using namespace std;
// Bellman Ford (src) -> return int SP[NODES ] ;
// 1-  distance[node]  = inf excpet distanct[src] = 0 ;
//   edge list
//  run it n-1 times
// {2- iterate over edge list and relax
    // if(distance[v] > distance[u] + cost  )
    //          distance[v] = distance[u]+cost ;
    //}
// O(n * m ) --> worst case
// O(m) --> best case

// 1- used to detect negative cycles
vector<long long> BellmanFord(int src, vector<pair<pair<int ,int>,int>> & edgelist  , int & nodes , int& edges , bool isDirected , bool & negativecyle){
    vector<long long > SP(nodes  +1 , 1e17 );
    SP[src] = 0 ;
    for(int j = 0 ; j < nodes  ; j++) {
        for(int i =0 ;i <  edges ; i++) {
            int u = edgelist[i].first.first  , v = edgelist[i].first.second , w = edgelist[i].second ;
            // relax edge from u to v ;
            if(SP[v] > SP[u] + w ) {
                SP[v] = SP[u] +w ; 
                if(j == (nodes -1) ){
                    negativecyle = 1 ;
                }
            }
            if(!isDirected){// remove if directed graph
                if(SP[u] > SP[v] + w ) {
                    SP[u] = SP[v] +w ; 
                    if(j== (nodes -1) ){
                        negativecyle = 1;
                    }
                }
            }
        }
    }
    return  SP;
}


int main() {
    int n, m ;
    cin >> n >> m ;
    vector<pair<pair<int ,int > , int >> EdgeList ;
    for(int i =0 ;i <  m ; i++) {
        int u  , v , w ;
        cin >> u >> v >> w ;
        EdgeList.push_back({{u , v } , w });
    }
    bool neg = 0 ;
    vector<long long > SP = BellmanFord(0  , EdgeList ,  n, m , 1 , neg) ;
    for(int i =0 ;i < n ; i++) {
        cout << "Shortest path from " << 0 << " to " << i << " is : " << SP[i] << " " << endl;  
    }
    cout << (neg?"negative cycle exit":"no negative cyle") << endl;

    return 0;
}