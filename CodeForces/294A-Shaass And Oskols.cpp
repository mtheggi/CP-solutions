#include <iostream>
#include <vector>
using namespace std;
int main()
{

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        int c;
        cin >> c;
        v[i] = c;
    }
    int t;
    cin >> t;
    for (int j = 0; j < t; j++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        if (a - 1 >= 0)
        {
            v[a - 1] += b - 1;
        }
        if (a + 1 < n)
        {
            v[a + 1] += v[a] - b;
        }
        v[a] = 0;
    }
    for (int k = 0; k < n; k++)
    {
        cout << v[k] << endl;
    }
}