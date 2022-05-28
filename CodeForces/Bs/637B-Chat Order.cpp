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
        
        set<string> set ;
        vector<string > v; 
        int n  ;
        cin >> n ;

        while(n--){
          string s ;
          cin  >> s ;
          v.push_back(s);
        }
        for (int i = v.size()-1; i >= 0; i--)
        {   if(set.count(v[i]) == 0){
                set.insert(v[i]);
                cout << v[i] <<endl;
            } 
            else {
                continue;
            }
        }
        



    return 0;
}
