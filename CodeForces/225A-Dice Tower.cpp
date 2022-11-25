#include <bits/stdc++.h>
#define el "\n"
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL)

using namespace std;

int main()
{
    fastio;
    int n ,t ; cin >> n >>t ;
        while(n--){
            int a  ,b  ; cin >> a >> b ;
            if(a == t || a == 7-t || b==t || b == 7-t) {
                cout << "NO" <<endl ;return 0;
            }


        }
        cout << "YES"<<endl; 
    return 0;
}
