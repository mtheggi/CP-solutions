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

    string s ;
    cin >> s ;
    for (int i = 0; i < s.length(); i++)
    {  
          
        if(s[i] == '9' && i == 0){
           cout << '9' ; 
        }else if(s[i]>'4') {
             cout << ('9'-s[i]) ;
        }else {
            cout << s[i];
        }
        
    }
    cout << endl; //
    



    return 0;
}
