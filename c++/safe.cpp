#include <iostream>
using namespace std;
const int array_size = 20;
const int array_size2 = 20100;   // determine the constant size of the array
int FindAndCountMissing(int arr1[], int arr2[])
{
    int s = arr1[0]; // intial value to increment
    int count = 0; // number of missings
    int j = 0; // index of the second array
    for (int i = 0; i < array_size; i++)
    {
        if (s != arr1[i]) // check if the sequnce of number is broken 
        {
            arr2[j] = s; // setting the missing value of array to the the second array
            count++; // increment to the number of missings 
            j++; // increment to the index of the second array

            i--; // decrement the element of the first array to make sure that the element in the array compared to the right number
        }
        s++; // increment to the number that we compare array to 
    }
    return count;
}

int main()
{
    int arr1[array_size]; // 
    for (int i = 0; i < array_size; i++) // inserting array1
    {
        cin >> arr1[i];
    }

    int arr2[array_size2];
    for (int i = 0; i < array_size2; i++) // since the value of element in the first array -10000<a<10000
   {                                        //  then i will set array2 to a value that is not in array1 and to make sure
                                            // that while COUTing the array2 that i will not print extra places in memory.
                                            // and also to avoid dynamic allocation of the second array.
        arr2[i] = -11000;
    }

    int count = FindAndCountMissing(arr1, arr2);
    int j = 0;
    while (arr2[j] != -11000 && j < array_size2) // while the value not equal to -11000 the print the array 
    {
        cout << arr2[j] << " ";
        j++;
    }
    if (count == 0) // if count = 0 i will print extra line , so this if is to make sure that i will not do that. 
    {
        cout << count ;
    }else{
        cout << endl; //
        cout << count ;
    }
}