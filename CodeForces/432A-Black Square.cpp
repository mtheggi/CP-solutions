#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a1, a2, a3, a4;
    cin >> a1 >> a2 >> a3 >> a4;
    string z;
    cin >> z;
    char ch1 = '1';
    char ch2 = '2';
    char ch3 = '3';
    char ch4 = '4';
    int count1 = count(z.begin(), z.end(), ch1);
    int count2 = count(z.begin(), z.end(), ch2);
    int count3 = count(z.begin(), z.end(), ch3);
    int count4 = count(z.begin(), z.end(), ch4);

    cout << (count1 * a1 + count2 * a2 + count3 * a3 + count4 * a4) << endl;
}