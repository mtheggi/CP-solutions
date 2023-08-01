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
    int n;
    cin >> n;
    vector<string> v ;
    set<string> set;
    map<string,int > map ;
    for (int i = 0; i < n; i++)
    {
        string s ;
        cin >> s ;
        v.push_back(s); ; 
        map.insert({s,0}) ;
    }
    for (int i = 0; i < n; i++)
    {
        int  size = set.size(); 
        set.insert(v[i]) ;
        if(size == set.size()) {
             map[v[i]]++; 
            cout << v[i] << map[v[i]] <<endl;
        }else {
            cout << "OK" << endl; 
        }
    }
    
    
    
        
    

    return 0;
}
