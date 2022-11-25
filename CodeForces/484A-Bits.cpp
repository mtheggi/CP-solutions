#include <bits/stdc++.h>
#define el "\n"
#define ll long long
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

using namespace std;
ll MSB(ll x)
{
    ll msb = 0;
    while (x)
    {
        x >>= 1; // x = x >> = 1 ;
        msb++;
    }
    return msb - 1;
}
int main()
{
    fastio;
    int t;
    cin >> t;
    while (t--)
    {
        ll a, b;
        cin >> a >> b;
        ll x = a;
        int msb = MSB(b);
        for (int i = 0; i <= msb; i++)
        {
            if ((x | 1ll << i) <= b)
            {
                x = x | 1ll << i;
            }
            else
            {
                break;
            }
        }
        cout << x << endl;
    }

    return 0;
}
