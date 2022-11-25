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
    int t;
    cin >> t;
    vector<int> v(t);
    vector<int> z(t, 0);
    for (int i = 0; i < t; i++)
    {
        cin >> v[i];
    }
    int max = -1;
    int cnt = 0;
    //! --------------------------------------------------------------
    if(t ==1 ){
        cout << 1 ;
        return 0;
    }
    
    
    for (int i = 0; i < t; i++)
    {
        if (i == 0)
        {
            for (int j = i; j < t - 1; j++)
            {
                if (v[j] >= v[j + 1])
                {
                    cnt++;
                }else{
                    break;
                }
                
            }
        }
        else if (i == t - 1)
        {
            for (int j = t-1; j >=0 ; j--)
            {
                if (v[j] >= v[j-1])
                {
                    cnt++;
                }else
                    break;
            }
        }else{
           
            for (int j = i; j >=0 ; j--)
            {
                if (v[j] >= v[j-1])
                {
                    cnt++;
                }else 
                break;
            }
             for (int j = i; j < t - 1; j++)
            {
                if (v[j] >= v[j + 1])
                {
                    cnt++;
                }else {
                    break;
                }
            }
        }
        if(cnt >= max){
            max = cnt;
        }
        cnt = 0;
    }
    cout << max +1 ;
    return 0;
}
