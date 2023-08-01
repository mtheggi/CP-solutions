/*

Author : Mohamed Heggi
Date : 30 may 2022
problem Link: https://codeforces.com/problemset/problem/160/B
Techinque : Greedy

*/
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
    int n;
    string s;
    cin >> n >> s;
    sort(s.begin(), s.begin() + n);
    sort(s.begin() + n, s.end());
    bool isGreater = s[0] > s[n] ? true : false;

    for (int i = 0; i < n; ++i)
    {
        if (isGreater)
        {
            if (s[i] <= s[i + n])
            {
                cout << "NO" << endl;
                return 0;
            }
        }
        else
        {
            if (s[i] >= s[i + n])
            {
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    cout << "YES" << endl;
    return 0;
}
