#include <iostream>
using namespace std;
#include <vector>
int main()
{
    int n, b, d;
    int sum = 0;
    int c = 0;
    cin >> n >> b >> d;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        v[i] = a;
    }
    //int z;
    int i = 0;
    for (; i < n; i++)
    {
        if (v[i] <= b && sum <= d)
        {
            sum += v[i];
        }
        if (sum > d)
        {
            c++;
            sum = 0;
        }
    }
    // if (sum > d)
    // {
    //     c++;
    // }
    cout << c;
}