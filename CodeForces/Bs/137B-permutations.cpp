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
    int t ;
    cin >>t ; 
    vector<int> v;
    vector<bool>freq(5005 ,false) ;
    int c =  0;
    for (int i = 0; i < t  ; i++)
    {
        int a ;
        cin >> a;
        v.push_back(a);
        freq[a] =true;
    }
    sort(v.begin(), v.end());

    for (int i = 1; i <=t  ; i++)
    {
        if(!freq[i]) c++;
    }

    cout << c << endl ;
    


    return 0;
}