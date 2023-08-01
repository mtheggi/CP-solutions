#include<bits/stdc++.h>

using namespace std;
int const N = 1e5 +4  ;
#define ll unsigned long long

ll dp[N] ;
// dp[i] --> min cost to reach n from i ; n is the last index
// recurrent -> dp[i] = min(dp[i+1] + delta1 , dp[i+2] + delta2) ; 
vector<int>  h ;
void solve() {
  int n; cin >> n ;
  h.resize(n+1);
  for(int i =0 ;i < n ; i++) cin >> h[i] ;
  dp[n-1] =0 ; dp[n-2] = abs(h[n-1]  - h[n-2]) ;
  for(int i = n -3 ; i>=0 ; i--) dp[i] = min(dp[i+1] + abs(h[i+1] - h[i]) , dp[i+2] + abs(h[i+2] - h[i])  ) ;
  cout << dp[0] << endl;
  for(int i =0 ;i < n ; i++) {cerr << dp[i] << endl; }
}

int main() {
    int t = 1;
    //    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}