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
        vector<pair<int, int>> v(n);
        set<int> set;
        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            v[i].first = a;
            v[i].second = i + 1;
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < n - 1; i++)
        {
            if (v[i].first == v[i + 1].first)
            {
                set.insert(v[i + 1].second - v[i].second);
            }
        }
        int z = *set.begin();
        if (z == 0)
            cout << -1 << endl;
        else
            cout << z + 1 << endl;
    }

    return 0  ;
}
