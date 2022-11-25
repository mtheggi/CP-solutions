#include <bits/stdc++.h>
#include <unordered_map>
#define el "\n"
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL)

using namespace std;
#define ll long long  
int main()
{
    fastio;
#ifndef ONLINE_JUDGE
    freopen("input", "rt", stdin);
#endif
#ifndef ONLINE_JUDGE
    freopen("output", "wt", stdout);
#endif

       vector<ll> v(2e5 +2 ) ;
       int t ;
       cin >> t;
       char m;int n;
       cin >> m >> n;
       v[n] = 0 ;
       ll r = 0 , l =  0 ;
       t--;
       while(t--){
           char s ; int z;
           cin >> s >>z ;
           if(s == 'L'){
               l--;
               v[z] =l; 
           }else if (s == 'R'){
               r++;
               v[z] = r;
           }else {

                cout << min(abs(v[z] - l), abs(v[z] - r)) << "\n";

           }
           



       }

    return 0;
}
