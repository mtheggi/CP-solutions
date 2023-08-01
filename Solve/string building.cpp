#include <bits/stdc++.h>
#define el "\n"
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
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

    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        vector<int> v;
        int count = 0;
        int countb = 0;

        for (int i = 0; i < s.length(); i++)
        {
            count++;
            if (i != s.length() - 1)
            {
                if (s[i] != s[i + 1])
                {
                    v.push_back(count);
                    count = 0;
                }
            }else {
                v.push_back(count);
            }
        }
        bool flage = false;
        for (int i = 0; i < v.size(); i++)
        {
            if(v[i] == 1){
                    flage = true; 
            }
        }
        if(flage){
            cout << "NO" <<endl;
        }else {
            cout << "YES" <<endl;
        }
        
    
    }

    return 0;
}
