#include <bits/stdc++.h>
#define el "\n"
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL)

using namespace std;
#define ll long long
int const N = 1e9+1  ;
bool valid(ll ans, ll left , ll help, map<ll , ll> mp ){

    for(auto i  : mp){
        if(ans >  i.second){
            help += ((ans - i.second)/2);
        }else if(ans < i.second){
            left+= (i.second - ans);
        }
    }
    if(left<=help)
        return 1 ;
    else
        return 0;

}
int main()
{

    fastio;
    int t ; cin  >> t ;
    while(t--){
        ll n,m ; cin >> n >> m ;
        map<ll ,ll > mp ;
        for (ll i = 1; i <n+1 ; ++i) {
            mp[i] =0 ;
        }
        for (ll i = 0; i <m ; ++i) {
            ll a;  cin >> a ;
            mp[a]++;
        }
        ll st =1 , end= m *2, mid , ans;
        while(st<=end){
            mid = (st +end)/2 ;
            if(valid(mid,0 ,0, mp)){
                ans =mid ;
                end = mid -1;
            }else{
                st = mid +1 ;
            }
        }
        cout <<ans << el;

    }


    return 0 ;
}
