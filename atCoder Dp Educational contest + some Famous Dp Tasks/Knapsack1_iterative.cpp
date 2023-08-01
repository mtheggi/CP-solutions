#include<bits/stdc++.h>

using namespace std;
#define ll long long

void solve() {
    int n, w ;
    cin >> n  >> w ;

    vector<pair<ll, ll>> items(n+1); // pair<weight  , value >
    vector<vector<ll>> dp (n+2 , vector<ll>(w+2 , 0 ));
    for(int i = 0 ;i < n ;i++) {cin >> items[i].first  >> items[i].second  ; }
    // dp[i][j] --> standing at indx = i with bag capacity  =j what is the max value you could get ? .

    for(int indx =0 ;indx< n ; indx++ ) {
        for(int capacity =0; capacity <= w ; capacity++){
            if(indx == 0) {
                if(capacity>= items[indx].first) {dp[indx][capacity] =items[indx].second ;  }
                else dp[indx][capacity] = 0 ;
            }else {
                int c= (capacity >= items[indx].first) ? 1: 0 ;
                dp[indx][capacity] = max(dp[indx-1][capacity] , dp[indx-1][capacity - items[indx].first * c ] + items[indx].second *c  ) ;
            }
        }
    }
    cout << dp[n-1][w] << endl;
}

int main() {
    int t = 1;
    //    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}