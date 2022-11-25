#include <bits/stdc++.h>
#define el "\n"
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL)

using namespace std;
#define ll  long long

int main()
{
    fastio;
    ll t ;cin>> t;
    while(t--){
        ll N , Q ;
        cin >> N >> Q ;
        vector<ll> sc(N+1, 0);
        set<pair<ll ,ll>> st ;
        for (ll i = 1; i <=N ; ++i) {
            st.insert(make_pair(0,i)); 
        }
        ll win =1; ll last =0;
        for( ll i = 1 ; i<=Q ;i++ ) {
            ll x, p;
            cin >> x >> p;
            st.erase(make_pair(-1ll * sc[x], x));
            sc[x] += p;
            st.insert(make_pair(-1ll * sc[x], x));
            if (win != (*st.begin()).second) {
                win = (*st.begin()).second;
                last = i;
            }
        }
        cout << last <<el;
    }
    return 0 ;
}