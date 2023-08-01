#include<bits/stdc++.h>

using namespace std;
int const N = 1e5 +4  ;
#define ll unsigned long long

ll dp[N] ;
// dp[i] --> min cost to reach n from i ; n is the last index
// recurrent -> dp[i] = min(dp[i+1] + delta1 , dp[i+2] + delta2) ;
vector<int>  h ;
void solve() {
    int n, k ;
    cin >> n  >> k ;
    h.resize(n+1);
    for(int i =0 ;i < n ; i++) cin >> h[i] ;
    memset(dp  , INT_MAX , sizeof  dp ) ;
    dp[n-1] =0 ; dp[n-2] = abs(h[n-1]  - h[n-2]) ;
    for(int i = n -3 ; i>=0 ; i--){
        for(int j =1 ;j <= k ; j++) {
            if(i+ j < n )
                dp[i] = min(dp[i] , dp[i+j] + abs(h[i+j] - h[i]))  ;
        }
    }
    cout << dp[0] << endl;

}

int main() {
   int t = 1;
    //    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}