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

    ll  n ; cin >> n ; 
    set<ll> set ;
    for (int i = 0; i < n; ++i)
    {
    	ll a ; cin >> a ; 
    	set.insert(a);
    }

    cout << set.size() <<endl; 

    return 0;
}
