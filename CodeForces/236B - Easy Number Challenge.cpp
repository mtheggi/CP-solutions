#include <bits/stdc++.h>
#define el "\n"
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

int const N = 1e6 + 2;
int d[N];
int a, b, c;

int divisors(int n)
{ // O(sqrt(n))
    int cnt = 0;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            cnt++;
            if (n / i != i)
                cnt++;
        }
    }
    return cnt;
}
void NumberOfDivisor()
{
    for (int i = 1; i < a * b * c; ++i)
    {
        d[i] = divisors(i);
    }
}
using namespace std;
#define ll long long
int main()
{
    fastio;
    NumberOfDivisor();
    cin >> a >> b >> c;
    ll sum = 0;

    for (int i = 1; i <= a; ++i)
    {
        for (int j = 1; j <= b; ++j)
        {
            for (int k = 1; k <= c; ++k)
            {
                sum += divisors(i * j * k);
            }
        }
    }

    cout << sum % (1 << 30) << el;
    return 0;
}
