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
        ll a;
        cin >> a;
        string s;
        cin >> s;
        bool flage = true;
        for (int i = 0; i < s.length(); ++i)
        {
            if (s[i] == 'W')
                continue;
            else
            {
                ll cntr = 0;
                ll cntb = 0;
                ll j = i;
                while (j < s.length() && s[j] != 'W')
                {
                    if (s[j] == 'R')
                    {
                        cntr++;
                    }
                    else if (s[j] == 'B')
                    {
                        cntb++;
                    }
                    j++;
                }
                i = j-1;
                if (cntr == 0 || cntb == 0)
                {
                    flage = false;
                    
                }
            }
        }

        if (flage)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}
