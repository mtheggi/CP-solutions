#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;

int main()
{
    fastio;
#ifndef ONLINE_JUDGE
    freopen("input", "rt", stdin);
#endif
#ifndef ONLINE_JUDGE
    freopen("output", "wt", stdout);
#endif


int n ,k ;
int c = 0 ;
cin >> n >> k ;
while(n--){
      string x ;
      cin >>x ;
      bool f = true;
      for (size_t i = 0; i < k+1; i++)
      {
          if(x.find(to_string(i)) == string::npos){
              f =false;
          }
      }
      if(f){
          c++;
      }else{
          continue;
      }
      
    
}
cout << c ;
    return 0;
}
