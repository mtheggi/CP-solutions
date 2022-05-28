#include <bits/stdc++.h>
#define el "\n"
#define ll long long
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

using namespace std;
int count_digit(ll number)
{
    int digits = 0;
    while (number)
    {
        number /= 10;
        digits++;
    }
    return digits;
}
set<ll> st;
ll n;
void solve(ll d)
{
    ll limit = (1 << d) - 1;
    for (ll msk = 0; msk <= limit; msk++)
    {
        ll val = 0;
        int cnt4 = 0;
        int cnt7 = 0;
        for (int i = 0; i < d; i++)
        {
            if (msk & (1 << i))
                val *= 10, val += 7, cnt7++;
            else
                val *= 10, val += 4, cnt4++;
        }
        if (cnt4 == cnt7 && val >= n)
        {
            st.insert(val);
        }
    }
}

int main()
{
    fastio;
    cin >> n;
    int count_digits = count_digit(n);
    solve(count_digits);
    solve(count_digits + 1);
    solve(count_digits + 2);
    cout << *(st.begin()) << endl;

    return 0;
}
