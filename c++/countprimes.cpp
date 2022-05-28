#include <iostream>
using namespace std;
const int array_size = 20; // determine the constant size of the array  
int CountPrimes(int arr[])
{
    int count = 0; // set the counter to count the number of primes
    for (int i = 0; i < array_size; i++) // to loop over the array
    {    bool flag = true;// flag to indicat if the number if prime
        if(arr[i] == 2){ // check if the prim is 2 because 2 is the least prime number, and the next for loop will start from 2
            count++;
        }else if (arr[i] > 2){
            for(int j = 2; j < arr[i]; j++){
                if(arr[i]%j == 0){ // testing all number that are less than arr[i], to see if it is divisible by any number or not...
                flag =false; // if the number is divisible by any number then , it is not prime , and set flag to false.
                    break;
                }
            }
            if(flag){ // if falge is true then number is prime, and increment count
                count++;
            }
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
    int count = CountPrimes(arr);
    cout << count <<endl;
}