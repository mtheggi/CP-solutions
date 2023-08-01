#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<cmath>
#include<utility>
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
    int t ;
    cin >>t ;
    while(t--){
        int n ;
        cin >>n ;
        vector<int> v(n) ;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i] ;
            
        }
        sort(v.begin(),v.end());
        int ans = 2000;
        for (int i = 0; i < n-1; i++)
        {
            ans = min(ans,v[i+1]-v[i]);
        }
        
        cout << ans <<endl;

    }
        



    return 0;
}
