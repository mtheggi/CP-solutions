#include <iostream>
#include <string>
using namespace std;
int main()
{
    int a, b;
    string z;
    cin >> a;
    cin >> b;
    cin >> z;

    while (b != 0)
    {
        for (int i = 0; i < a; i++)
        {

            if (z[i] == 'B' && z[i + 1] == 'G')
            {
                z[i] = 'G';
                z[i + 1] = 'B';
                i++ ;
            }
            else
            {
                continue;
            }


        }
        b = b-1 ;

    }
    cout << z << endl;
}