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
    int n, l, r, k;
    cin >> n >> l >> r >> k;
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
    }

    ll limit = (1 << n) - 1;
    int cnt = 0;

    for (ll i = 0; i <= limit; ++i)
    {
        ll sum = 0;
        int mx = INT_MIN;
        int mn = INT_MAX;
        if (__builtin_popcount(i) >= 2)
        {
            for (int j = 0; j < n; ++j)
            {
                if ((1ll << j) & i)
                {

                    mx = max(mx, v[j]);
                    mn = min(mn, v[j]);
                    sum += v[j];
                }
            }
        }

        if ((mx - mn) >= k && sum >= l && sum <= r)
            cnt++;
    }

    cout << cnt << endl;
    return 0;
}
