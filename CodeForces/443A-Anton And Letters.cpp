#include <iostream>
#include <set>
#include <string>
using namespace std;
int main()
{
    string s;
    set<char> set;
    getline(cin,s);
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '}' || s[i] == '{' || s[i] == ',' || s[i] == ' ')
            continue;
        else
            set.insert(s[i]);
    }
    cout << set.size() << endl;
}
//{a, b, c}