#include <bits/stdc++.h>
#define el "\n"
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL)

using namespace std;
#define ll long long
int const N = 1e7 +6  ;

int main()
{
    fastio;
    string s ;
    int nb , ns, nc, pb ,ps ,pc ;
    ll r;cin >>s ;
    cin >> nb >>ns >> nc >> pb >> ps >> pc >>r;
    int B =0,S =0,C =0;     
    for (int i = 0; i < s.size() ; ++i) {
        B+=(s[i] == 'B');
        S+=(s[i] == 'S');
        C+=(s[i] == 'C');
    }

    ll x ,temp = -1, start =0 ,end =1e13 ;
    while(start <= end){
        x  =( start + end )/2;
        ll Priceneeded = max(0*1ll,B*x - nb*1ll  )*pb +  max(0*1ll,C*x - nc*1ll  )*pc + max(0*1ll,S*x - ns*1ll  )*ps ;
        if(Priceneeded> r){
            end = x-1;
        }else {
            start = x+1;
            temp = max(temp ,x );
        }
    }
    cout << temp <<endl ;
    return 0 ;
}
