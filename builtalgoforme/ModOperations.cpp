#include<bits/stdc++.h>
using namespace std; 
#define  ll long long 

class ModOp{
    long long  MOD ;
public :
    ModOp():MOD(1e9 + 7 ){}
    ModOp(ll M ):MOD(M){}
    void setMOD(ll M ) {MOD = M ; }
    ll add( ll a, ll b ) {return(a+ b + MOD) % MOD ; }
    ll mul(ll a,ll b ) {return( a * b % MOD);}
    ll FastPower(ll a , ll b ) {
        ll z = 1;
        while(b)
        {
            if(b % 2 == 1) z = mul(z, a);
            a = mul(a, a);
            b /= 2;
        }
        return z;
    }
    ll inverseMod(ll a ) {return FastPower( a , MOD-2 ); }
    ll divide(ll a, ll b ) { return mul(a , inverseMod(b)) ;}
};