#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    string s = "abcdefghijklmnopqrstuvwxyz";    
    string ans = "";
    for (int i = 0; i < n; i++)
    {
        ans = ans + s[i % k]; 
        /* 
        ! ln 12 explaination
        * after i --- > k , it wll reapeat again from 1 to --- > 0   
            * s[1] -- > s[2] --> s[3] -----> .... s[0]------------------------
            *                                                                 |
            *                                            .....s[2]<---s[1]<---|
    
        */
    }
    cout << ans << endl;
}
