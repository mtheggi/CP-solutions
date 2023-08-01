#include <bits/stdc++.h>
#define el "\n"
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

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

    int n, t, k, d;
    cin >> n >> t >> k >> d;
    int patches = (n / k) + ((n % k) != 0);
    int t1 = t * patches;
    int o1 = 0;
    int o2 = d;
    while (patches != 0)
    {
        if (o1 <= o2)
            o1 = o1 + t;
        else
            o2 = o2 + t;
        patches--;
    }
    string result = (max(o1, o2) < t1) ? "YES" : "NO";

    cout << result;

    return 0;
}
