#include <bits/stdc++.h>
#define el "\n"
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL)

using namespace std;
#define ll long long
const int N = 1e6;bool prime[N];
void sieve(){ // O(n * (log(log(n)))
    memset(prime, true, sizeof prime);
    prime[0] = prime[1] = false;
    for(int i = 2; i * i < N; i++){
            for(int j = i + i; j < N; j += i){
                prime[j] = false;  
                }
            }
        
    }

int main()
{
    fastio;
    sieve();
    ll n ; 
    cin >> n ;     
    while(n--){
        ll a ; 
        cin >>a ; 
        ll s = sqrt(a);
        if(s*s == a && prime[s]){
            cout << "YES" <<el;  
        }else {

            cout <<"NO" <<el ;
        }
    } 

    return 0;
}
