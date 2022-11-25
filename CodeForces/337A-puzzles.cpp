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
    int n, m;
    cin >> n >> m;
    vector<int> v(m);
    for (int i = 0; i < m; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    set<int> v2;
    for (int i = 0; i <= m - n; i++)
    {
        v2.insert(v[i + n - 1] - v[i]);
    }
    cout << *(v2.begin());
    return 0;
}
