#include <bits/stdc++.h>
#define el "\n"
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

using namespace std;
#define ll long long
const int N = 3e4;
bool prime[N];
void sieve()
{ // O(n * (log(log(n)))
    memset(prime, true, sizeof prime);
    prime[0] = prime[1] = false;
    for (int i = 2; i * i < N; i++)
    {
        for (int j = i + i; j < N; j += i)
        {
            prime[j] = false;
        }
    }
}

int main()
{
    fastio;
    sieve();
    ll n;
    cin >> n;
    int Cnt = 0;
    for (int i = 1; i <= n; ++i)
    {
        int Cnt2 = 0;
        for (int j = 1; j * j <= i; ++j)
        {
            if (i % j == 0)
            {
                if (prime[j])
                {
                    Cnt2++;
                }
                if (j != i / j)
                {
                    if (prime[i / j])
                    {
                        Cnt2++;
                    }
                }
            }
        }
        if (Cnt2 == 2)
        {
            Cnt++;
        }
    }
    cout << Cnt << endl;
    return 0;
}
