#include <bits/stdc++.h>
#define el "\n"
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define ll long long
using namespace std;
int main()
{

    fastio;
#ifndef ONLINE_JUDGE
    freopen("input", "rt", stdin);
#endif
#ifndef ONLINE_JUDGE
    freopen("output", "wt", stdout);
#endif

    ll n;
    cin >> n;
    ll mn, mx;
    ll r = n % 7;
    ll weeks = n / 7;
    ll z = weeks * 2;
    mx = z;
    mn = z;
    if (r == 6)
    {
        mn++;
        mx += 2;
    }
    else if (r <= 2)
    {
        mx += r;
    }
    else
    {
        mx += 2;
    }

    cout << mn << " " << mx << endl;

    return 0;
}
