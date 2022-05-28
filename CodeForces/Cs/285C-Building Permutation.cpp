#include <bits/stdc++.h>
#define el "\n"
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

using namespace std;
#define ll long long
int main()
{
    fastio;
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    ll ans = 0;
    for (size_t i = 0; i < n; i++)
    {
        ll z = v[i] - (i + 1);
        if (z < 0)
        {
            z = z * -1;
        }
        ans += z;
    }
    cout << ans << el;
    return 0;
}
