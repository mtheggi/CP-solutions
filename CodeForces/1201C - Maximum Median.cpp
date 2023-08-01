#include <bits/stdc++.h>
#define el "\n"
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL)

using namespace std;
#define ll long long
int const N = 2e9 +1  ;
int n ,k ;
bool valid(ll mid, vector<int> &v)
{
    ll moves =0 ;
    for (int i = n/2 ; i <n ; ++i) {
        if( mid - v[i] >=0 ){
            moves+=( mid - v[i]);
        }
    }

    if(moves>k){
        return false;
    }else {
        return true;
    }

}

int main()
{
    fastio;
    cin >> n >> k ;
    vector<int>v(n);
    for (int i = 0; i <n ; ++i) {
        cin >> v[i] ;
    }
    sort(v.begin(),v.end());
    ll st =0 ,end = 2e9, mid, ans ;
    while(st<=end){
        mid = (st + end)/2 ;
        if(valid(mid, v )){
            ans = mid ;
            st = mid+1;

        }else {
            end =mid -1 ;
        }

    }
    cout << ans  <<endl ;

    return 0 ;
}
