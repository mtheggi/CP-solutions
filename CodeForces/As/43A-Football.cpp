#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

using namespace std;

int main()
{
    fastio;
    int t;
    cin >> t;
    string s ;
    cin >> s; 
    string z ;
    string c ;
    z=s;
    t--;
    int x =1 ,y = 0 ;
    while(t--)
    {
       cin >> s;    
        if(z == s){
            x++;
        }else{
            c=s ;
            y++;
        }        
    }
    string ans = (x>y) ? z : c ;
    cout << ans << endl ;
    return 0;
}