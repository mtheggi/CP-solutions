#include <bits/stdc++.h>
#define el "\n"
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL)

using namespace std;
#define ll long long
int main()
{
    fastio;
    int t , n,s ; cin >>t ;
    while(t--){
        cin >> n >> s;
        vector<int> v(n);
        vector<int>prefix( n+1 ,0 );
        for (int i = 0; i <n; ++i) {
            cin >> v[i];
        }
        for (int i = 1; i <=n ; ++i) {
            prefix[i]= prefix[i-1] + v[i-1];
        }
        int mid, mn= INT_MAX,z;

        for (int i = 1; i<=n ; ++i) {
            int st=i,end = n ;int cnt=0 ;
            while(st<=end ){
                mid= (st +end)/2 ;
                if(prefix[mid]- prefix[i-1] > s ){
                    end = mid-1 ;
                }else if (prefix[mid] - prefix[i-1] < s ){
                    st= mid +1;
                }else {
                    z = (n)- (mid -i +1  ) ;
                    mn =min(mn, z );
                    st = mid +1 ;
                    cnt++;
                }
            }

        }
        mn =(mn==INT_MAX)?-1:mn;
        cout << mn<<el;
    }
    return 0 ;
}
