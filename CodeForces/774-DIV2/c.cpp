#include <iostream>
using namespace std;
bool checkfact(int n)
{
    for (int i = 1;; i++)
    {
        if (n % i == 0)
        {
            n /= i;
        }
        else
        {
            break;
        }
    }

    if (n == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool powerOfTwo(int n)
{
    if (n == 0)
    {
        return false;
    }
    while (n != 1)
    {
        n = n / 2;
        if (n % 2 != 0 && n != 1)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int t;
    cin >> t;
    long long int n;
    while (t--)
    {
        int k = 0;
        cin >> n;
        int sum = 0;
        int x = n;
        while (sum != n)
        {
            if (powerOfTwo(x) || checkfact(x))
            {
                sum = sum + n;
                k++;
            }
            else
            {
                continue;
            }
            x--;
        }
        if (k == 0)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << k << endl;
        }
    }
}