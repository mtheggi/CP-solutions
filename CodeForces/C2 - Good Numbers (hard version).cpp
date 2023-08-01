#include <bits/stdc++.h>
#define el "\n"
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
using namespace std;
#define ll long long
const int N = 1e5;
bool ord[N];
bool check(ll n)
{
    int z;
    while (n)
    {

        z = n % 3;
        n /= 3;
        if (z == 2)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    fastio;
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        if (check(n))
        {
            cout << n << el;
        }
        else
        {
            ll power = 1, ans = 0;
            while (ans < n)
            {
                ans += power;
                power *= 3;
            }
            while (power)
            {
                if ((ans - power) > n)
                {
                    ans -= power;
                }
                power /= 3;
            }

            cout << ans << el;
        }
    }

    return 0;
}