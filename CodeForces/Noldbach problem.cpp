#include <bits/stdc++.h>
#define el "\n"
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

using namespace std;
#define ll long long
const int N = 1001;
bool p[N];
void sieve()
{ // O(n * (log(log(n)))
    memset(p, true, sizeof(p));
    p[0] = p[1] = false;
    for (int i = 2; i * i < N; i++)
    {
        for (int j = i + i; j < N; j += i)
        {
            p[j] = false;
        }
    }
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

    sieve();
    vector<int> clean;
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < N; ++i)
    {
        if (p[i])
        {
            clean.push_back(i);
        }
    }
    int Cnt = 0;
    for (int i = 0; i < clean.size() - 1; ++i)
    {
        int l = clean[i] + clean[i + 1] + 1;
        if (l <= n && p[l])
        {

            Cnt++;
        }
    }
    // cout << Cnt <<el;
    if (Cnt < k)
    {

        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << el;
    }
    return 0;
}
