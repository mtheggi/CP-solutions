#include <bits/stdc++.h>
#define el "\n"
#define ll long long 
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL)

using namespace std;
const int N = 2e5 +50 ;
const int mod = 1e9 +7;  

int sum[N];
int prefixsum[N];

int main()
{
    fastio;
#ifndef ONLINE_JUDGE
    freopen("input", "rt", stdin);
#endif
#ifndef ONLINE_JUDGE
    freopen("output", "wt", stdout);
#endif
    // ! partial sum  

        int n,m,k;
        cin >> n >> m>> k;
        for (int i = 1; i <= n; i++)
        {   int a,b ;
            cin >>a>>b ;
            sum[a]++;
            sum[b+1]--;
        }
        for (int i = 1;i<N;i++ )
        {
            sum[i] = sum[i] + sum[i-1];
        }
        for (int i = 1; i <N; i++)
        {
             if(sum[i]>=m){
                 prefixsum[i] = 1;
             }
             prefixsum[i] = prefixsum[i-1] + prefixsum[i];
        }
        while(k--){
            int x,t;
           cin >> x>>t;
            cout << prefixsum[t] - prefixsum[x-1] << endl; 

        }
        




    return 0;
}
