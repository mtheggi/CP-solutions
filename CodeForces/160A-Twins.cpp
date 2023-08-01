#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;

int main()
{
    fastio;
    
    int n ; //
    cin >> n ;
    vector<int> v(n);
    int a ;
    int sumall = 0 ;
    int sum = 0 ;
    for (int  i = 0; i < n; i++)
    {   
        cin >>a ;
        v[i]= a ;
        sumall = sumall +a ;  
    }
    sort(v.begin(), v.end(),greater<int>());
    int j = 0 ;
    while(sum <= sumall){
        sum =sum + v[j] ;
        sumall = sumall - v[j] ;
        j++;

    }
    cout << j++  << endl ; 
    return 0;
}