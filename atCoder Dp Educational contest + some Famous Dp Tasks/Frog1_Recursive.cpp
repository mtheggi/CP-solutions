#include<bits/stdc++.h>
using namespace std;

int const N = 1e5 +4  ;
int dp[N] ;
vector<int>  h ;
int n;

int findpath(int indx){ // blackbox function  that get min cost from i to n ;
    if(indx+1 >= n ) return 0;

    int &ret = dp[indx];

    if(~ret) return ret;

    int path2= INT_MAX;
    int path1  = findpath(indx+1) +  abs(h[indx] - h[indx+1]) ;

    if((indx+2 )< n )
        path2 = abs(h[indx] - h[indx+2]) + findpath(indx+2 );

    return  ret = min(path1 , path2) ;

}

void solve() {
  cin >> n ;
  h.resize(n+1);
  for(int i =0 ;i < n ; i++) cin >> h[i] ;
  memset(dp , -1 , sizeof dp ) ;
  cout << findpath(0) << endl;
}

int main() {
   int t = 1;
    //    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}