#include<bits/stdc++.h>
using namespace std;
#define ll  long long

int const N = 1e5 +20  ;
ll const inf = 1e17 ;

int n, w ;
vector<pair<ll, ll>> items; // pair<weight  , value >
ll dp[102][N];     // dp[i][j] --> standing at indx i -> what is the minimum weight to get the  value j  ;


void solve() {
    cin >> n  >> w ;
    items.resize(n+1);
    int max_val  =0 ; ll ans =0 ; 
    for(int i = 0 ;i < n ;i++) {cin >> items[i].first  >> items[i].second  ; max_val += items[i].second ;     }

    for(int i = 0  ; i < 102 ; i++) for(int j = 0 ; j < N ; j++) if(j!= 0 )dp[i][j]= inf; else dp[i][j] =0 ;

    for(int indx =0 ;indx  < n ; indx++) {
        for(int val = 0 ; val<= max_val ; val++) {
            if(indx == 0 ){
                if(val == items[indx].second ) dp[indx][val] = items[indx].first ;
            }else {
                    ll c = ( val- items[indx].second) >=0 ? 1 : 0 ;
                    dp[indx][val] =min(dp[indx - 1][val],
                                       dp[indx - 1][val - items[indx].second * c] + items[indx].first * c) ;
            }
        }
    }
    for(int pos =0 ; pos < n ; pos++) {
        for (ll value = 0; value <= max_val; value++) {
            if (dp[pos][value] <= w) {
               ans = max(ans, value);
            }
        }
    }
    cout << ans << endl;
}

int main() {
    int t = 1;
    //    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}