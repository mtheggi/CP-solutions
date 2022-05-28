#include <iostream>
using namespace std;
const int array_size = 20;

/*
since the definition of coprime numbers is that the greatest common divisor is 1 .
so my strategy is make a function that calculate the the greatest common divisor of 
any two numbers . then , make another function that loop over the array and check
if the greatest common divisor between mate and element in the array is 1, if so increment the counter
*/
int greatest_common_divisor(int a, int b)
{   
    if(a==0 ) return b;
    if(b==0) return a;
    int x = 0;
    for (int i = 1; i <= a && i <= b; i++) // save the greatest common divisor
    {   

        if (a % i == 0 && b % i == 0)
        {

            x = i;
        }
    }
    return x;
}
int solve(int arr[],int n )
{   int count = 0;
    for (int i = 0; i < array_size; i++)
    {   
        if(greatest_common_divisor(arr[i],n) == 1 ){ // loop over all the array to check the GCD 
            count++; 
        }
    }
    return count;
}
int main()
{
    int arr[array_size];
    for (int i = 0; i < array_size; i++)
    {
        cin >> arr[i];
    }
    int n ;
    cin >> n ;
    int count = solve(arr, n);
    cout << count << endl;
}