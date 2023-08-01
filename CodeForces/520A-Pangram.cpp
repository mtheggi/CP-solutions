#include <string>
#include <algorithm>
#include <iostream>
#include <cctype>
#include <set>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;

int main()
{
    fastio;
    int n;
    cin >> n;
    set<char> s;
    string x;
    std::cin >> x;
    for (int i = 0; i < n; i++)
    {
        int c = x[i];
        if (islower(c))
            x[i] = toupper(c);
    }
    for(int i = 0; i < n; i++){
        s.insert(x[i]);
    }
   string r = (s.size() == 26) ? "YES" : "NO" ; 
    cout << r <<endl; 
    return 0;
}