#include<bits/stdc++.h>

using namespace std;
int const N = 1e5 +1  ;
int const fkneg = 1e4 ;
#define ll long long
#define f first
#define s second
int n , k;
vector<int> num ;

int dp[110][N] ;

int addMod(int a , int b  ){
    return(( a%k + b%k + k   )% k );
}
int subMod(int a , int b ) {
    return(( a%k - b%k + k )% k );
}


bool checkDiv(int currentRem , int indx ){
    if(indx >=n )
        if(currentRem%k == 0 ) return 1 ; else return  0 ;

    int & ret = dp[currentRem%k][indx];
    if(~ret) return (ret==1);

    bool option1 = checkDiv(addMod(currentRem , num[indx]), indx + 1) ;
    bool option2 = checkDiv(subMod(currentRem, num[indx]), indx+1 );
    if(option1|| option2) ret =1 ;else   ret = 0 ;
    return   ret ;
}

void solve() {
    cin >>n >> k  ;
    num.resize(n) ;
    memset(dp , -1 , sizeof dp) ;
    for(int i =0 ;  i< n ; i++) cin >> num[i] ;
    string ans = checkDiv((num[0]%k + k)%k  , 1 )? "Divisible" : "Not divisible";
    cout << ans << endl;

}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}