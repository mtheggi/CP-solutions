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
    int  n,m ;
    cin >> n >> m;
    vector<int> v(n) ;
    for (size_t i = 0; i < n; i++)
    {
        cin >> v[i] ;
    }
    sort(v.begin(),v.end());
    int ans = 0 ;
    int i =0 ;
    while(m--){
        if(v[i] < 0){
        ans = ans + v[i] ;
        } 
        i++;
    }

    cout << abs(ans) << endl;

    return 0;
}
