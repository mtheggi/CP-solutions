#include <bits/stdc++.h>
#define el "\n"
#define ll long long 
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL)

using namespace std;
const int N = 2e5 +50 ;
const int mod = 1e9 +7;  
int main()
{
    fastio;
#ifndef ONLINE_JUDGE
    freopen("input", "rt", stdin);
#endif
#ifndef ONLINE_JUDGE
    freopen("output", "wt", stdout);
#endif
        int n ;
        cin >> n;
        vector<ll> v(n+1,0);
        vector<ll> vpresum(n+1,0);
        vector<ll> vpremin(n+1,0);
        for (int i = 1; i <=n; i++)
        {
            cin >> v[i];
        }
        for (int i = 1; i <=n; i++)
        {
            vpresum[i] = vpresum[i-1] + v[i];
        }
        sort(v.begin()+1, v.end());
        for (int i = 1; i <=n; i++)
        {
            vpremin[i] = vpremin[i-1] + v[i];
        }
        int m ;
        cin >>m;
        while(m--){
            int t,l,r;
            cin >>t >>l>>r;
            if(t ==1 ){

                cout << vpresum[r] - vpresum[l-1] << endl;
            }else {

                cout << vpremin[r] - vpremin[l-1] <<endl;
            }



        }


    return 0;
}
