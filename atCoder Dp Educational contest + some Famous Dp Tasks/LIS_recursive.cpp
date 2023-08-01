#include<bits/stdc++.h>

using namespace std;
int const N = 1e3 +1  ;
#define ll long long
#define f first
#define s second
vector<int> num ;
int n;
int dp[N][N];
int LIS(int indx , int lastindx ) {
    if(indx > n ) return 0;
    int a =0 ;
    int & ret = dp[indx][lastindx] ;
    if(~ret) return ret ;
    if(num[indx] > num[lastindx] ) {
        a = 1+ LIS(indx+1 , indx );
    }
    int b = LIS(indx+1, lastindx);
    return  ret = max(a, b ) ;


}

void  buildLIS(int indx , int lastindx ) {
    if(indx > n ) return ;
    int a =0 , b =0 ;
    if(num[indx] > num[lastindx] ) {
        a = 1+ LIS(indx+1 , indx );
    }
    b = LIS(indx+1 , lastindx) ;
    if(a > b ) {
        cout << num[indx] << " " ;
        buildLIS(indx + 1 , indx ) ;
    }else {
        buildLIS(indx+1 , lastindx) ;
    }


}




void solve() {
    cin >> n ;
    num.resize(n+2 );
    for(int i =1 ; i <= n; i++ ) cin >> num[i] ;
    num[0] = -1;
    memset(dp , -1 , sizeof dp ) ;
    cout << LIS(1, 0 )  << endl;
    buildLIS(1,0 ) ;
}

int main() {

    int t = 1;
    //    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}