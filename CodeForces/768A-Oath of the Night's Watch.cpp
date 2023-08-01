#include <bits/stdc++.h>
#include<vector>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;
#define ll long long int
int main()
{
    fastio;
    ll n;
    cin >> n;
    ll a;
    ll count = 0;
    vector<ll> v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a;
        v[i]=a;
    }
    sort(v.begin(), v.end());
    ll e1 = v[0];
	ll e2 = v[n-1];
	for( ll i = 0;i < n;i++)
	{
		if(v[i] != e1 && v[i] != e2)
		{
			count++;
		}
	}	
    cout << count << endl; 
    return 0;
}