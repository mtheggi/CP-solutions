#include<bits/stdc++.h>

using namespace std;
int const N = 3e3 +5  ;
#define ll long long;
#define len(x) (int)x.size()
int dp[N][N] ;
string s ,t;

int LCS(int indx1 , int indx2 ){
    if((indx1 >= len(s))  || (indx2 >= len(t))) return 0 ;
    int a  ,b , c;
    a =b = c = 0 ;
    int & ret = dp[indx1][indx2] ;

    if(~ret) return ret ;

    if(s[indx1] == t[indx2])  {   a = 1 + LCS(indx1+1 , indx2 +1 ); }
    else { b = LCS(indx1+ 1 , indx2) ; c = LCS(indx1 , indx2+ 1) ;  }
    return  ret = max(a , max(b ,c )) ;

}

void buildLCS(int indx1 , int indx2 ){
    if(indx1 >= len(s)  || indx2 >= len(t)) return ;
    int a  ,b , c , mx ;
    a =b = c = 0 ;
    if(s[indx1] == t[indx2])  {   a = 1 + LCS(indx1+1 , indx2 +1 ); }
    else { b = LCS(indx1+ 1 , indx2) ; c = LCS(indx1 , indx2+ 1) ;  }
    mx = max(a , max(b,c)) ;
     if(mx == a && s[indx1] == t[indx2]) {
         cout << s[indx1]  ;
         buildLCS(indx1+1, indx2+1);
     }else if(mx ==b ) {
         buildLCS(indx1+1, indx2);
     }else {
         buildLCS(indx1, indx2+1);
     }
}


void solve() {
    cin >> s >> t;
    memset(dp ,  -1 ,  sizeof  dp );
    buildLCS(0,0) ;
}

int main() {
    int t = 1;
    //    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}