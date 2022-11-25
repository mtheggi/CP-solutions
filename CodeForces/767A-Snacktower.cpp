#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n, a;
    cin >> n;
    int s = n;
    vector<int> v(n + 1);
    vector<bool> b(n + 1);
    for (int i = 1; i < n + 1; i++)
    {
        cin >> a;
        v[i] = a;
    }

    for (int i = 1; i < n + 1; i++)
    {
        b[v[i]] = true;
        while (b[s] && s > 0)
        {
            cout << s << " ";
            s--;
        }
        cout << " " << endl;
    }
}