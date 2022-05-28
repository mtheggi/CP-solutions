#include <iostream>
using namespace std;
const int array_size = 20;
/*
my strategy to solve this problem is the following : 
1- i will make a funtion that check for prime number
2- i will take "Z"(the mate ) i will check for both z+2 and z-2 
if one of them is not prime then i will set it to a value which is not prime (even)
to make sure that when i compare (z+2 - z-2 )to the array , i will not square any 
wrong/not-prime number.

*/

bool isPrime(int n) // check if the number is prime or not.
                    // i did explain the all of it in the first question.
{   if(n == 0){ // zero is not prime.
    return false;
    }
    if(n== 1 ){ // one is not prime
        return false;
    }
    if(n== 2 ){ // 2 is prime
        return true;
    }
    bool flag = true;
    if (n > 2) 
    {
        for (int j = 2; j < n; j++)
        {
            if (n % j == 0) // if i find a common factor , then it is not a prime number 
            {
                flag = false;
                break;
            }
        }
    }
    return flag; // return a boolean 
}

void SquareTwins(int arr[], int n)
{
    int z = n + 2; // add 2 to check for prime-twin
    int x = n - 2; //subtract 2 to check for prime-twin
    if(!isPrime(z)){
        z = 6; /* set the z for even number (which is invalid input ) 
            to make sure that the value of the elment in the array 
        does not change when the number is not prim */
    
    }
    if(!isPrime(x)){ x =6 ;} // same condition as z 
    for (size_t i = 0; i < array_size; i++)
    {   
        if (arr[i] == z || arr[i] == x) // check if the number is equal to z or x , if so , square the value 
        {
            arr[i]= arr[i] * arr[i] ; // setting value in place in the old array 
        }
        else
        {
            continue;
        }
    }
}
int main()
{
    int arr[array_size];
    for (int i = 0; i < array_size; i++)
    {
        cin >> arr[i];
    }
    int n;
    cin >> n;
    SquareTwins(arr, n);
    for (size_t i = 0; i < array_size; i++)
    {
        cout << arr[i] << " ";
    }
    
}