#include <iostream>
#include <string>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        string r = (s.length() > 10) ? (s[0] + to_string(s.length() - 2) + s[s.length() - 1]) : s;
        cout << r << endl;
    }
}