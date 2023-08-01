#include<bits/stdc++.h>
using namespace std;
#define ll  long long

int const N = 1e5 +20  ;
ll const inf = 1e17 ;

int n, w ;
vector<pair<ll, ll>> items; // pair<weight  , value >
ll dp[102][N];

ll findMinWeight(int indx , int value) { // deal with this function as a black box . to get the minimum weight can be taken with this value
    if(indx > n || value < 0 ) {
        if(!value) return 0;
        else return inf; // to invalidate any path that does not take items with the sum of values equal to "value" ;
    }
    ll &ret = dp[indx][value] ;

    if(~ret ) return ret;

    ll weight_1 = items[indx+1].first + findMinWeight(indx+1 , value- items[indx+1].second) ;
    ll weight_2 =  findMinWeight(indx+1 , value );

    return ret = min(weight_2, weight_1) ;


}

void solve() {
    cin >> n  >> w ;
    items.resize(n+2);
    ll max_value  =0 ;
    for(int i = 1;i <= n ;i++) {cin >> items[i].first  >> items[i].second ; max_value += items[i].second;       }
    for(int i = 0  ; i < 102 ; i++) for(ll j = 0 ; j < max_value+2; j++) dp[i][j] = -1  ;
    ll ans  = 0 ;
    for(ll val =max_value ;val >=0 ; val--) {
        if(findMinWeight(0 , val) <= w ){
            ans = val; break;
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