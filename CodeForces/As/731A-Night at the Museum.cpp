#include <bits/stdc++.h>
using namespace std;
int main()
{
    string z;
    cin >> z;
    string a = "abcdefghijklmnopqrstuvwxyz";
    int sum = 0;
    int pointer = 0;
    for (int i = 0; i < z.length(); i++)
    {
        int j = a.find(z[i]);
        int steps = min(abs(pointer - j), 26 - abs(pointer - j));
        pointer = a.find(z[i]);

        //`cout << steps <<endl;
        sum = sum + steps;
    }
    cout << sum << endl;
}