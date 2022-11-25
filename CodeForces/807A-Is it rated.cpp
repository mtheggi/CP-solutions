#include <bits/stdc++.h>
#include <utility>
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"
#define F first
#define S second

using namespace std;

int main()
{
    fastio;
    int z;
    cin >> z;
    int x =0;
    vector<pair<int,int>> As(z);
    vector<int> Bs(z);
    int j = z ;
    for (int i = 0 ; i < z; i++)
    {
        int a, b;
        cin >> a >> b;
        if (a != b)
        {   x++;
            cout << "rated" << endl;
            return 0;
        }
            Bs[i] = b;
            As[i].first = a;
            As[i].second = j;
            j--;   
    }
    sort(As.begin(),As.end());
    for(int i =0; i <z; i++){
       if( As[i].second != (i+1)){
           cout << "unrated" << endl;
          return 0 ;
       }  
    }
    cout << "maybe" << endl;
    return 0;
}