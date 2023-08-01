#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"
#define ll long long
using namespace std;
//! solution one is better that the second because of time complexity
int main()
{
    fastio;
    string s;
    cin >> s;
    ll t = 0;
    ll h = 0;

    // ! oslution 1

    for (int i = 4; i < s.length(); i++)
    {
        if (s[i] == 'l')
        {
            if (s[i - 1] == 'a' && s[i - 2] == 't' && s[i - 3] == 'e' && s[i - 4] == 'm')
            {
                t += h;
            }
        }
        else if (s[i - 4] == 'h' && s[i - 3] == 'e' && s[i - 2] == 'a' && s[i - 1] == 'v' && s[i] == 'y')
        {
            h++;
        }
    }
    cout << t;
    //  ! complexity  O(N)
// **********************************************************************************************************   
   
    // * solution 2
    /*
       for (int i = 4; i < s.length(); i++)
       {
           if (s[i-4] == 'h' && s[i-3] == 'e' && s[i-2] == 'a' && s[i-1] == 'v' && s[i] == 'y')
           {
               int j = i+1;
               for (; j < s.length(); j++)
               {
                   if(s[j] == 'l' && s[j-1] == 'a' && s[j-2] == 't' && s[j-3] == 'e' && s[j-4] == 'm'){
                       t++;
                   }
               }

           }
       }
       cout << t ;
       //   complexity  O(NxM)
   */
    return 0;
}