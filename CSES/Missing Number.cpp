#include <bits/stdc++.h>
#define el "\n"
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
 
using namespace std;
 // 
int main()
{
    fastio;
#ifndef ONLINE_JUDGE
    freopen("input", "rt", stdin);
#endif
#ifndef ONLINE_JUDGE
    freopen("output", "wt", stdout);
#endif
 
    long long n;
    cin >> n;
    long long sum = 0 ;
    long long sum2 =  (n * (n+1)) / 2;
    while (n>=2 ){
        int x ;
        cin >> x ;
        sum  = sum +x ;
        n--;
    }
    cout << sum2 - sum ; 
    return 0;
}