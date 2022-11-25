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

    int t ;
    cin >> t ; 
    while (t--)
    {   bool falge = true;
        int n ; cin >> n ; 
        map<int ,int > mp;
        for (int i = 0; i < n; i++)
        {
                int a ; cin >> a ;
                mp[a]++;
        }
        for (auto i : mp)
        {
            if(i.second >= 3){
                falge =false;
                cout << i.first<<endl; 
                break;
            }
        }
        if(falge){
            cout << -1 <<endl ;
        }

    }

    return 0;
}
