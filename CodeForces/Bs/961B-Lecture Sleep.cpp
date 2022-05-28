#include <bits/stdc++.h>
#define el "\n"
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
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

        int k,n;
        cin >> n>>k;
        //* i do not know why on earth i used pair , but u can make two vector
        vector<pair<int,int>> v(n+1, pair<int,int>(0,0));
        for (int i = 1; i <= n; i++)
        {
            cin  >> v[i].first;
        }
        for (int i = 1; i <= n; i++)
        {
            cin >> v[i].second;
        }
        int sum =0 ;
        for (int i = 1; i <=n; i++)
        {
            if(v[i].second == 1){
                sum+=v[i].first;
                v[i].first = 0;
            }

        }
        for (int i = 1; i <= n; i++)
        {
            v[i].first += v[i-1].first;
        }
        int ans = INT_MIN;
        for (int i = k; i <= n; i++)
        {

            int z = v[i].first - v[i-k].first;
            ans = max(ans,z);
        }
        
        
        cout << sum +ans<<endl; 
        
        
      // ! the below solution will give TIME_LIMIT_EXCEEDED  
        /*
        int z = INT_MIN;
        
        for (int i = 1; i <= n-k+1; i++)
        {   
            
            
            int ans= 0;
            for (int j = i; j < i+k; j++)
            {   
                if(v[j].second ==0){

                    ans+=v[j].first;
                }
            }
            z = max(z,ans);
        }
        
        cout << sum +z <<endl; 

        */

    return 0;
}
