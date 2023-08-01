#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <cmath>
#include <utility>
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

    int n, m; //
    cin >> n >> m;
    vector<pair<int, int>> v;
    int s = m;
    while (s--)
    {
        int a, b;
        cin >> a >> b;
        v.push_back({b, a});
    }
    sort(v.begin(), v.end(), greater<pair<int, int>>());
    int ans = 0; //
    int i = 0 ;
    while(n && i< m )
    {
        if (n <= v[i].second)
        {

            ans = ans + n * (v[i].first);
            cout << ans << endl; //
            return 0;
        }
        else
        {
            ans = ans + (v[i].second)* (v[i].first); 
            n = n - v[i].second;
              
        }
        i++ ;
    }
    cout << ans  << endl; 

    return 0;
}
