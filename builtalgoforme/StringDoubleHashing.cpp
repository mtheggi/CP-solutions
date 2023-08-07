#include<bits/stdc++.h>

using namespace std;
int const N = 1e4 +1 , MOD1 = 1e9 + 7 , base1 = 31, MOD2 = 1e9+9 , base2 = 37;
#define debug(x) cout << #x << " " ; for(int i =0 ; i< x.size() ;i++) cout << x[i] << " " ; cout << endl;

#define ll   long long
ll pw[N]; // pw[i] = base^i
ll inv[N], pre[N];
ll pw2[N] , inv2[N], pre2[N];
ll add(ll a, ll b , ll MOD ) {return (0ll+ a + b + MOD ) % MOD ;}
ll mul(ll a , ll b, ll MOD  ) {return (1ll * a * b ) % MOD ;}
ll fastpower(ll a  , ll b , ll MOD) {
    if(!b) return  1 ;
    ll temp = fastpower(a , b/2, MOD );
    temp = mul(temp , temp, MOD);
    if(b&1) temp = mul(temp , a, MOD );
    return temp ;
}
void precalc(){
    pw[0]= pw2[0] = inv2[0] =  1 ; inv[0] = 1 ;
    for(int i =1 ; i < N ; i++) {
        pw[i] = mul(pw[i-1] , base1, MOD1);
        inv[i] = fastpower(pw[i],MOD1-2, MOD1);
        pw2[i]= mul(pw2[i-1] , base2 , MOD2);
        inv2[i] = fastpower(pw2[i], MOD2-2, MOD2) ;
    }
}
void GenerateHash(string &str){
    ll hashvalue =0 , hasevalue2  =0 ;
    for(int i =0 ;i < str.size() ; i++) {
        hashvalue = mul(0ll+ str[i] - 'a' +1 , pw[i], MOD1);
        if(i) pre[i]= add(pre[i-1], hashvalue, MOD1); else pre[i]= hashvalue;

        hasevalue2 = mul(0ll+ str[i] - 'a' +1 , pw2[i], MOD2);
        if(i) pre2[i]= add(pre2[i-1], hasevalue2, MOD2); else pre2[i]= hasevalue2;
    }
}
pair<int ,int > QueryHash(int l , int r  ) {

    pair<int ,int > val;
    val.first = pre[r], val.second = pre2[r];

    if(l) val.first  = add(val.first , -pre[l-1], MOD1) , val.second = add(val.second , -pre2[l-1] , MOD2);
     val.first =  mul(val.first , inv[l], MOD1);
     val.second = mul(val.second , inv2[l] , MOD2) ;
     return val ;

}

void solve() {
    string s ;cin >> s; 
    precalc();
    GenerateHash(s);
    
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
#endif
    int t = 1;
       // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
