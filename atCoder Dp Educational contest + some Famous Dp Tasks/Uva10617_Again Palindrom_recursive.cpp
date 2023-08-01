#include<bits/stdc++.h>

using namespace std;
int const N = 101  ;
#define ll long long

ll dp[N][N] ;

string str ;

ll NumbersOfPalin(int i , int j ) {

    if(i == j ) return 1 ; // cnt one charachter as a palindrom
    if(i+1 == j ) return (2 + (str[i] == str[j]) ) ; // cnt two charachter as a palindrom + if they are equal cnt 1 more palindrom
    ll & ret  = dp[i][j] ;
    if(~ret) return ret ;
    ll a = 0 ;

    if(str[i] == str[j]) a +=(1 + NumbersOfPalin(i+1 , j-1 )) ; // if they are equal cnt 1 more palindrom + cnt all palindroms between them
    a += NumbersOfPalin(i+1, j ) ; // cnt all palindroms between  i+1 , j 
    a += NumbersOfPalin(i , j-1) ;// cnt all palindroms between i , j-1 ; 
    a -= NumbersOfPalin(i+1, j-1 ) ;  //subtract all palindroms between i+1 , j-1 because we cnt them twice 

    return ret = a;
}


void solve() {
    cin >> str ;
    memset(dp , -1 , sizeof  dp ) ;
    cout << NumbersOfPalin( 0 , str.length()-1  )  << endl;
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}