#include<bits/stdc++.h>

using namespace std;
int const N = 2e5+3;

vector<int> g[N];
int dp[N] ;

int FindLongestPath(int src ) {

    if(g[src].size()  == 0 ) return  1 ;
    if(dp[src] != 0) return dp[src] ;

    for(auto  i : g[src]) {
        dp[src] = max(dp[src] , 1 + FindLongestPath(i) );
    }

    return dp[src];

}

int main() {
    int n, m ,u ,v ;
    memset(dp , 0 , sizeof dp ) ;
    cin >> n >> m ;
    for(int i =0 ;i < m  ; i++) {
        cin >> u >> v;
        g[u].push_back(v);
    }
    int mx = -1 ;
    for(int i =1;i <= n ; i++) mx = max(FindLongestPath(i), mx  ) ;
    cout  << mx -1 << endl ;

    return 0;
}