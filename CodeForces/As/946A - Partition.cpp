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
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int ans = 0;
    int neg = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] < 0)
        {
            neg += v[i];
        }
        else
        {
            ans += v[i];
        }
    }
    cout << ans - neg << el;

    return 0;
}
