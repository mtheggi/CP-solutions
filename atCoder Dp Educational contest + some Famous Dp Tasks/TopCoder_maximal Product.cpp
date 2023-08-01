#include<bits/stdc++.h>
/*
    problem link : https://community.topcoder.com/stat?c=problem_statement&pm=8760&rd=12171
*/
using namespace std;
#define ll long long
int  k , s ;
const int mxpos = 22 ;
const int mxrem = 1000;
ll dp[mxpos][mxrem] ;

ll mxprod(int  pos , int rem ){//

    if(rem == 0 ) {
        if(pos ==  k) return 1 ;
        else return 0;
    }
    if(pos == k  && rem != 0 ) return 0; // invalid case ;
    ll &ret  = dp[pos][rem] ;
    if(~ret) return ret;

    ll product = 0 ;
    for(int i =1 ; i <= rem ; i++) {
        product = max(product , i * mxprod(pos+1 , rem-i) ) ;
    }

    return ret =  product ;
}



void solve() {
    cin >> s >> k ;
    memset(dp , -1 , sizeof dp) ;
    cout << mxprod(0,s);
}

int main() {
    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}