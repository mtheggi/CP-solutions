#include<bits/stdc++.h>
using namespace std;
// Macros
#define RunIt ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define lld long double
#define el endl
#define re return
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define f first
#define s second
#define len(z) (int)z.size()
#define pb push_back
#define eb emplace_back
#define popcnt(a) __builtin_popcount(a)
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
// Debug
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " :" << x << endl;
#define debugv(v) cerr << #v << endl;  for(auto & i : v ) cerr << i << " " ; cerr << endl;
#define ShowTime cerr << "Code Takes  : " << (float) clock() / CLOCKS_PER_SEC << setprecision(7) <<  fixed << " Secs to run." << endl;
#else
#define debug(x)
#define debugv(v)
#define ShowTime
#endif
// constants
const int MOD = 1e9+7;
const double EPS = 1e-9;
const int N = 1e5 ,  M = 2e5 + 10  ;
// used Funcions
ll GCD(ll a, ll b) { return (a) ? GCD(b % a, a) : b; }
ll LCM(ll a, ll b) { return a * b / GCD(a, b); }
ll fastpow(ll b, ll p) { if (!p) return 1; ll ret = fastpow(b, p >> 1); ret *= ret; if (p & 1) ret *= b; return ret; }
// Uva Coin change 

vector<int> v=  {0, 1 ,5 , 10 , 25 ,50 };
int n;
int dp[7][7500];
ll EZ(int indx , int rem){
    if( rem< 0  || indx > 5 )re 0 ;
    if(rem == 0 ) re 1 ;
    ll z =0 ;
    if(dp[indx][rem] != -1 ) re dp[indx][rem];
    z+=EZ(indx, rem - v[indx]) ;
    z+=EZ(indx+1 , rem);
    re  dp[indx][rem] = z;
}   

int main() {
    RunIt;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
    // freopen("Error", "w", stderr);
#endif
//    int tc =1 ;
//    cin >> tc;
    for(int i = 0 ;i < 7 ;  i++)for(int j =0 ;j <7500 ; j++ ) dp[i][j] = -1 ;
   int dump=  EZ(1 ,7499 );
    while(cin  >> n ){
        cout << EZ(1 , n) << el;
    }

    ShowTime
    return 0 ;
}

