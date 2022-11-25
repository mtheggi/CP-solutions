#include <iostream>
#include <string>
using namespace std;
int main()
{
    string a, b;
    cin >> a >> b;
    int index = 1;
    for (int i = 0; i < b.length(); i++)
    {
        if (a[index - 1] == b[i])
        {
            index++;
        }
        else
        {
            continue;
        }
    }
    cout << index << endl;
}
