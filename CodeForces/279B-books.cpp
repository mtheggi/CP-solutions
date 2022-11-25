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
#ifndef ONLINE_JUDGE
    freopen("output.txt", "wt", stdout);
    freopen("input.txt", "rt", stdin);
#endif
  /*
   // solution 1
    int  n, t ;
    cin >> n>> t ;
    vector<int> v(n) ;
    for(int i = 0; i <n ; ++i)
            cin >> v[i] ;
    int ans = 0;
    int sum  =0 ;
    int r =0;
    for(int i =0 ; i < n ; i++){
         while(r < n && sum+v[r] <=t ){
             sum+=v[r];
             r++;
         }
         ans = max(ans,r-i );
         sum-=v[i];
    }
    cout << ans << endl ;

   */
    // solution 2 // nlogn using PREFIX SUM AND BINARY SEARCH
    int n ,t ;
    cin >> n >> t  ;
    vector<int> v(n+1) ;
    v[0] =  0 ;
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
    }
    for (int i = 1; i < n+1; ++i) {
        v[i]+=v[i-1];
    }
    int ans =0 ;
    for(int i  =1  ; i <=n ;i++ ){
        int st = i , end = n, mid ;
        while(st <=end ){
            mid = (st + end )/2 ;
            if(v[mid]- v[i-1] <= t){
                ans = max(ans, mid - i+1 ) ;
                st = mid + 1;
            }else if (v[mid]- v[i-1] > t){
                end = mid -1 ;
            }

        }

    }
    cout  << ans << endl;
   
   
    return 0 ;
}
