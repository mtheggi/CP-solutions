#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;

int main()
{
    fastio;
    string s = "qwertyuiopasdfghjkl;zxcvbnm,./";
    string z;
    char shift;
    cin >> shift;
    cin >> z;
    int index ;
    for (int i = 0; i < z.length(); i++)
    {   
        index = s.find(z[i], 0);
        if(shift == 'L')
            cout << s[index+1];
        else 
            cout << s[index - 1 ];
    }
    cout << endl;
    return 0;
}