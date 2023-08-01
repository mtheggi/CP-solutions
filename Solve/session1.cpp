#include <bits/stdc++.h>
#define el "\n"
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL)

using namespace std;

int main()
{
    fastio;
#ifndef ONLINE_JUDGE
    freopen("input", "rt", stdin);
#endif
#ifndef ONLINE_JUDGE
    freopen("output", "wt", stdout);
#endif

    
    int n;
    cin >> n; //
    vector<int>v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i] ;
    }

    int mx = INT_MIN;
    bool rm = 0;
    int len = 1 ;

    for (int i = 1; i < n; i++)
    {
        if(v[i]> v[i-1] || rm){
            len++;
        }else{
            rm =true;
            mx = max(len, mx);
            len=1;
        }
    }
    
    return 0;
}
