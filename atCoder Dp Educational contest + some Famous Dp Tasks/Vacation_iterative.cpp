#include<bits/stdc++.h>
using namespace std;

int const N = 1e5 +4  ;
int n ,k ;
vector<int> a , b,  c;
int dp[N][4] ;
void solve() {
    cin >> n ;
    a.resize(n+1 , 0 );
    b.resize(n+1 ,0 ) ;
    c.resize(n+1 , 0 );
    for(int i =1 ;i <=  n ; i++) cin >> a[i] >> b[i] >> c[i] ;
    dp[1][1] = a[1] ; dp[1][2] = b[1]; dp[1][3] = c[1] ;
    for(int i =2;i <= n ; i++ ) {
        for(int j = 1;  j <= 3 ; j++) {
            int x , y ;
            int added ;
            if(j == 1 ) x=2 , y =3  , added =a[i];
            else if(j == 2) x =1 , y = 3 , added = b[i];
            else x = 1, y = 2 , added = c[i];

            dp[i][j] = max(dp[i][j] , max(dp[i-1][x] + added, dp[i-1][y] +added ) ) ;
        }
    }
    cout << max(dp[n][1] , max(dp[n][2] , dp[n][3] )) << endl;
}

int main() {
    int t = 1;
    //    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}