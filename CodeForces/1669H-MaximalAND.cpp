#include <bits/stdc++.h>
#define el "\n"
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

using namespace std;
#define ll unsigned long long
const int N = 1e5 + 2;
int setIthBit(int x, int i)
{
    return x | (1 << i);
}
bool checkBit(int x, int i)
{
    return x & (1 << i);
}
int MSB(int x)
{
    int msb = 0;
    while (x)
    {
        x >>= 1; // x = x >>1 ;
        msb++;
    }
    return msb - 1;
}
int main()
{
    fastio;
#ifndef ONLINE_JUDGE
    freopen("input", "rt", stdin);
#endif
#ifndef ONLINE_JUDGE
    freopen("output", "wt", stdout);
#endif
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> z;
        vector<int> v(35, 0);
        for (int i = 0; i < n; ++i)
        {
            int a;
            cin >> a;
            z.push_back(a);
            for (int i = 30; i >= 0; i--)
            {
                if (!((1 << i) & a))
                    v[i]++;
            }
        }
        ll ans = 0;
        for (int i = 30; i >= 0; i--)
        {
            if (v[i] <= k)
            {
                k -= v[i];

                ans += (1 << i);
            }
        }
        cout << ans << endl;
    }

    return 0;
}
