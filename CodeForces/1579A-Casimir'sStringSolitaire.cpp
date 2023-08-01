#include <iostream>
#include <string>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a = 0;
        int b = 0;
        int c = 0;
        string s;
        cin >> s;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == 'A')
                a++;
            else if (s[i] == 'B')
                b++;
            else if (s[i] == 'C')
                c++;
        }

        cout << (a + c == b ? "YES" : "NO") << endl;
        //cin.get();
    }
}