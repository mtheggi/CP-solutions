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
#ifndef ONLINE_JUDGE
    freopen("input", "rt", stdin);
#endif
#ifndef ONLINE_JUDGE
    freopen("output", "wt", stdout);
#endif
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    int t;
    cin >> t;
    while (t--)
    {
        int ans = 1e9;
        int a;
        cin >> a;
        int limit = (1 << 10) - 1;
        for (int i = 0; i <= limit; ++i)
        {
            int value = 0;
            int sum = 0;
            for (int j = 0; j < 10; ++j)
            {
                if (i & (1 << j))
                {
                    sum += arr[j];
                    value *= 10;
                    value += arr[j];
                }
            }
            if (sum == a)
            {

                ans = min(ans, value);
            }
        }

        ans = (ans == 1e9) ? -1 : ans;
        cout << ans << endl;
    }

    return 0;
}
