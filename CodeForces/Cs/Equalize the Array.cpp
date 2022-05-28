#include <bits/stdc++.h>
#define el "\n"
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

using namespace std;
#define ll long long
int main()
{
    fastio;
#ifndef ONLINE_JUDGE
    freopen("input", "rt", stdin);
#endif
#ifndef ONLINE_JUDGE
    freopen("output", "wt", stdout);
#endif
    int t;
    cin >> t;
    while (t--)
    {
        map<int, int> mp , mp2 ;
        int n;
        cin >> n;
        int z = n ;
        while (z--)
        {   int x;
            cin >> x;
            mp[x]++;
        } 
        for(auto i : mp ){ 
          mp2[i.second]++; 
        }

        ll finalans = 1e9;
        for (int c = 0; c <= n; c++)
        {    ll ans = 0 ;
            for(auto i : mp2){
                if(c < i.first) 
                    ans += ((i.first-c) * (i.second));
                else if (c == i.first) 
                    continue;
                else 
                    ans += (i.first * i.second);  
            }
            finalans = min(finalans, ans);
        }
        
        cout << finalans << endl; 
    }
    return 0;
}