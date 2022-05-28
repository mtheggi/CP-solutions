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

    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        for (int i = 0; i <= 32; ++i)
        {
            if (((1 << i) & a) && (1 << i) & b)
            {

                a = a & ~(1 << i);
                b = b & ~(1 << i);
            }
        }
        cout << a + b << endl;
    }

    return 0;
}
