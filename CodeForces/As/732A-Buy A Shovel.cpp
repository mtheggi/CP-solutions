#include <iostream>
using namespace std;
int main()
{
    int r, k;
    cin >> k >> r;
    if (k % 10 == 0)
    {
        cout << 1 << endl;
    }
    else
    {

        for (int i = 1; i < 10; i++)
        {
            int a = (i * k) % 10;
            if (a == r)
            {
                cout << i << endl;
                break;
            }
            else if (a == 0)
            {
                cout << i << endl;
                break;
            }
        }
    }
}