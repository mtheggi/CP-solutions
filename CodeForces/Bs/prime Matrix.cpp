#include <bits/stdc++.h>
#define el "\n"
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL)

#define ll long long
int const N = 1e6+1  ; 
int FP[N]; // FP[i] first prime morethan i, if i is not prime   
bool Isprime(int n) { // O(sqrt(n))
        if(n == 1)
            return false;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0)
                return  false;
        }
        return true; ;
}

void FPF(){  // largest prime 
    int last =0;
    for (int i = 1e6; i >= 1; i--)
    {   
        if(Isprime(i)){
            last= i;  
            FP[i] =i ;
        }
        FP[i] =last;  
    }

}
ll const Mod = 1e9 + 7 ;  
bool primes[N];
using namespace std;
int main()
{ 
    fastio ;
    int n ,  m ; 
    cin >>  n >> m ;
    vector<vector<int>> v( n, vector<int>(m));
    int ansrows = INT_MAX  ; 
    int anscol = INT_MAX  ;
    FPF();
    for(int i  =0 ; i <n ; i++ )
        for(int j  =0 ; j< m ; j++)
            cin >> v[i][j] ;

   for(int i =0 ; i < n ; i++){
            int sum =0 ; 
        for(int j =0 ; j <m ; j++){
            sum+= (FP[v[i][j]]-v[i][j]);
        }
        ansrows = min(sum ,ansrows);
    }

    for (int i = 0; i < m; ++i)
    {   int sum =0 ; 
        for (int j = 0; j < n; ++j)
        {   
                sum+= FP[v[j][i]]-v[j][i];
        }

        anscol = min(sum,anscol ) ;
    }
 
    cout << min(anscol , ansrows);

return 0; }
