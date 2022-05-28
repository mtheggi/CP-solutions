#include <bits/stdc++.h>
#define el "\n"
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL)

using namespace std;
const int N = 1e5 +2;
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

        int n,m,k;
        cin >> n >>m>>k;
        vector<ll> arr(n+2,0);
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
        }
        vector<vector<int>> operations(m+1, vector<int>(4,0));
        
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <=3; j++)
            {
                cin >> operations[i][j];
            }
            
        }
        vector<ll>partial(n+2,0);
        vector<ll>NumOfEachOperation(N,0);
        
        while(k--){
            int a,b;
            cin >> a>>b; 
            NumOfEachOperation[a]++;   
            NumOfEachOperation[b+1]--;
        }

        for(int i = 1; i <= N; i++){
            NumOfEachOperation[i]+=NumOfEachOperation[i-1];
        }


        for (int i = 1; i <= m; i++)
        {
            partial[operations[i][1]]+=(operations[i][3]*NumOfEachOperation[i]);
            partial[operations[i][2]+1]-=operations[i][3]*NumOfEachOperation[i];
        }
            

        for (int i = 1; i <=n; i++)
        {
            partial[i] =partial[i-1] + partial[i];
        }
        
        for (int i = 1; i <= n; i++)
        {
            cout << (arr[i]+ partial[i])<< " "; 
        }
        
        

    return 0;
}
