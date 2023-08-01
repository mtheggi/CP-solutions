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
    string s ;
    cin  >>s ;
    int size = s.length() ;
    int pos = -1 ;
    for (int i = 0; i < size; i++)
    {   if(s[i] % 2 == 0){
        if(s[i] < s.back()){
            pos= i ;
            break ;
        }
        else { pos = i ; }

        }
    }
    
    if(pos ==  -1 ){

        cout << -1 <<endl; 
    }else {
        swap(s[size-1] ,s[pos]) ;
        cout << s <<endl; 
    } 

}