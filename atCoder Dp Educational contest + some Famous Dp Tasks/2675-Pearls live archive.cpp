/*
    problem link  :https://vjudge.net/contest/366518#problem/X  ;
*/
// consecutive range style.  
#include<bits/stdc++.h>
using namespace std;
int const N = 1e3 +1  ;

int n;

int prlcnt[N] ;
int prlprice[N] ;
int dp[N][N];
int dp2[N] ; 
int findminCost(int currentIndx , int lastIndx) {
    if(currentIndx  == n ) 
        if(currentIndx == lastIndx) return  0  ; 
        else return INT_MAX  ; // invalidate the case where we grouped some pearls together and reached the end of the array ;  

    int & ret = dp[currentIndx][lastIndx] ;
    if(~ret) return ret ;

    int sum  = 10 ,option1  = INT_MAX  ,  option2 = INT_MAX ;

    for(int i = lastIndx; i <=currentIndx ; i++ ) sum+=prlcnt[i] ; // (pearlscnt + 10 ) * pearls price ;

    // stop grouping ;
    option1 = (sum * prlprice[currentIndx] + findminCost(currentIndx+1 , currentIndx +1 ) ) ;

    // continue grouping ;
    option2 = findminCost(currentIndx+1 , lastIndx) ;

    return  ret = min(option2 , option1) ;
}


int findmnCost2(int currentindx ){ // push lastindx to  loopl // better in memory ;
    if(currentindx == n ) return 0 ;
    int & ret = dp2[currentindx] ;
    if(~ret) return ret ;
    int sm = 0 ;
    int ans = INT_MAX;
    for(int  i = currentindx ; i< n ; ++i ) {
        sm+=prlcnt[i];
        ans = min(ans , (sm + 10 )* prlprice[i] + findmnCost2(i+1 )) ;
    }

    return ret =  ans ;
}





void solve() {
    cin >> n ;
    for(int i =0 ; i < n ; i++) cin >> prlcnt[i] >> prlprice[i] ;
 
    memset(dp , -1 , sizeof dp ) ;
    //memset(dp2, -1 , sizeof dp2 ) ;
    cout << findminCost(0 ,0 )  << endl;
    //cout << findmnCost2(0) << endl ;
    
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}