#include <bits/stdc++.h>
#define el "\n"
#define ll long long
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

#include <iomanip>
using namespace std;
int z = 0;
int cal_pos(const string &s)
{
    z = 0;
    int pos = 0;
    for (char i : s)
    {
        if (i == '+')
            pos++;
        else if (i == '-')
            pos--;
        else
        {
            z++;
        }
    }
    return pos;
}

int main()
{
    fastio;
#ifndef ONLINE_JUDGE
    freopen("input", "rt", stdin);
#endif
#ifndef ONLINE_JUDGE
    freopen("output", "wt", stdout);
#endif
    string s1, s2;
    cin >> s1 >> s2;
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    int pos = cal_pos(s1);
    int poscurr = cal_pos(s2);
    int limit = (1 << z) - 1;
    double cnt = 0;
    for (int msk = 0; msk <= limit; msk++)
    {
        int val = 0;
        for (int i = 0; i < z; ++i)
        {
            if (msk & (1 << i))
            {
                val++;
            }
            else
            {
                val--;
            }
        }
        if ((val + poscurr) == pos)
            cnt++;
    }
    double one = (1.00000) * (cnt) / (double)(1 << z);
    cout << setprecision(9) << one * 1.000000000 << endl;
    return 0;
}
