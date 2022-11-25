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

        int n; //
        cin >> n; // 
        map<int, int> map ;
        while(n--){
            int z;
            cin >>z;
            map[z]++;
        }
        
        int ans = -1;
        for (auto i : map)
        {
            ans = max(ans , i.second); 
        }
        cout <<ans <<endl;
     
    return 0;
}
