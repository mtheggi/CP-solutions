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
        int t ; cin >>t ;
        while(t--){
            int n ,m ; cin >> n >>m ;
            int restore =0 ;
            vector<int>v(n) ;
            for (int i = 0; i <n ; ++i) {
                    cin >> v[i];
            }
            for (int i = 0; i <n; ++i) {
                if(m>=v[i]){
                    m-=v[i];
                }else{
                    restore+=(v[i]-m);
                    m+=(v[i]-m);
                    i--;
                }
            }
            cout << restore <<endl;
        }
    return 0 ;
}
