#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"
#define ll long long
using namespace std;

int main()
{
    fastio;
    ll n, k;
    cin >> n >> k;
    if (k <= (n+1)/2)
    {
        cout << (k-1)*2 +1 << endl;
    }
    else
    {
            cout << (k - (n+1)/2) *2 << endl; 
    }
    return 0;
}