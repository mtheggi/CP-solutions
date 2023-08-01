#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

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
    int n, a;
    int cnt = 0;
    cin >> n >> a;
    vector<int> v(n);
    int sum =0;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sum = accumulate(v.begin(), v.end(), 0);
        
    if (a == 1 || a == n)
    {  
        cout << sum;
        return 0;
    }
    if(a-1 <= n-a){
        cnt = 0 ;
        int i = a ;
        int j = a-2 ;
        
        for (; j>=0;i++,j--)
        {
            if(v[j]!=v[i]){
                cnt++;
            }
        }
    }else {
        cnt = 0 ;
        int i = a-1 ;
        int j = a-1 ;
        
        for (; i < n;i++,j--)
        {
            if(v[j]!=v[i]){
                cnt++;
            }
        }
    }
    cout << sum - cnt << endl;



    return 0;
}
