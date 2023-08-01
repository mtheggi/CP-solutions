#include<bits/stdc++.h>
using namespace std;

int const N = 1e5 +4  ;
int dp[N] ;
vector<int>  h ;
int n ,k ;

int findpath(int indx){ // blackbox function  that get min cost from i to n ;
    if(indx+1 >= n ) return 0;

    int &ret = dp[indx];

    if(~ret) return ret;

    int path= INT_MAX;
    for(int i =1 ;i <= k ; i++) {
        if( indx  + i < n ) {
            path = min(path ,  abs(h[indx] - h[indx+i]) + findpath(indx+i) );

        }
    }

    return  ret = path ;

}

void solve() {
    cin >> n >> k  ;
    h.resize(n+1);
    for(int i =0 ;i < n ; i++) cin >> h[i] ;
    memset(dp , -1 , sizeof dp ) ;
    cout << findpath(0) << endl;
}

int main() {
    int t = 1;
    //    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}