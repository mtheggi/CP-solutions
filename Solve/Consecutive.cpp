#include <bits/stdc++.h>
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

         ll t ;
         cin >> t ;
         while(t--){
            ll n ;
            cin >> n ;
            vector<ll> v ;
            for (int i = 0; i < n; i++)
            {
                int a ;
                cin >>a ;
                v.push_back(a);
            }
            int d =0;
            for (int i = 0; i < n-1; i++)
            {
                d =d + v[i+1] - v[i] - 1;
            }
            
            if(d <= 2 )
                cout << "YES" <<endl; 
            else
                cout << "NO" <<endl; 

         }



    return 0;
}
