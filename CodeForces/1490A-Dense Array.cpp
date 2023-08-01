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
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        int count = 0;
        for (int i = 0; i < n - 1; i++)
        {
            int mn = min(v[i], v[i + 1]);
            int mx = max(v[i], v[i + 1]);
            while (mn * 2 < mx)
            {
                mn = mn * 2;
                count++;
            }
        }

        cout << count << endl;
    }

    return 0;
}
