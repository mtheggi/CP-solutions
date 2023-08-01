#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;

int main()
{
    fastio;
    string s ;
    cin >>s ;
    bool x = 1 ;
    for (int i = 0; i < s.length(); i++)
    {
            if(s[i]== 'W' && s[i+1]== 'U' && s[i+2]== 'B'){
                    i = i +2;
                    if(x==0){
                    cout << " ";
                    x=1;
                    }else {
                        continue ;
                    }
            }else {
                x=0;
                cout << s[i] ;
            }
    }
    
    return 0;
}