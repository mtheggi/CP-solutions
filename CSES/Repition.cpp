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
 
    int A = 0 ;
    string s ; 
    cin >>s ;
    int m = 0;
    for (int i = 0; i < s.length()-1; i++)
    {
        if(s[i]== s[i+1]){
            A++;
            
        }else {
            
            A = 0;
        }
        m = max (m,A);
    }
    cout << m +1 ;
 
 
 
    return 0;
}