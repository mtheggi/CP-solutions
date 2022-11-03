#include <bits/stdc++.h>
#define el "\n"
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL)

using namespace std;
#define ll long long
int const N = 2e9 +1  ;
int main()
{
    fastio;
    int t  ;
    cin >> t ;
    ll st = -2e9 , end  = 2e9 ;
    while(t--){
        string s ;
        ll x ;
        char a ;
        cin >> s >> x >>a ;
        if(a == 'Y'){
            if(s == ">="){
                st = max(x,st) ;
            }else if (s == "<="){
                end = min(x,end) ;
            }else if (s == "<"){
                end =  min(x -1 ,end) ;
            }else if (s == ">"){
                st = max(x +1 ,st) ;
            }

        }else {
            if(s == ">="){
                end =  min(x -1 ,end)  ;
            }else if (s == "<="){
                st = max(x+1 ,st)  ;
            }else if (s == "<"){
                st = max(x,st) ;
            }else if (s == ">"){
                end = min(x,end) ;
            }
        }


    }
    if(st > end){
        cout << "Impossible" <<endl;
    }else {
        cout << (st+end)/2 <<el;
    }



    return 0 ;
}
