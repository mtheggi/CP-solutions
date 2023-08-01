#include <iostream>
using namespace std;
const int array_size = 20; // setting size of the input array 
const int array_size2 = 20002; // setting the size of the output array and the worst case would be 20001 element 
                            // bec.  -10000 =<N  =<10000
/*
My solution is based on the face that the index of array is incrementd by for each elment 0 1 2 4 5 ..

my strategy to is as the following : 
1 -> setting the first element of the array to "S"  and i will consider 
    this as an initial counter ( all the element is greater that the intial ).
2 ->  let arr = { 1 2 3 4 5 }
        index--> 0 1 2 3  4
    (arr[index] - index) should be always equal to 1_( which is "S" and initial counter in this case)_ only if the the array contain sorted and consecutive.
    So i will loop over the array and check every time if 
        the intial counter "S" is not equal to arr[index]-index
3-> if the condition in the step 2 is wrong;
    then i will store the values of (index +s ) in the second array. 
*/

void FindandCountMissing(int arr[], int arr2[], int n, int &count)
{

    int s = arr[0]; // intial counter (first elemnt in the array)
    int j = 0 ; // index of arr2 
    for(int i = 0; i < n; i++){
        if(s != (arr[i]-i)){ // compare the the s to Arr[i]- i as written above. 
                
                while (s < arr[i] - i) { // storing the missing numbers in the second array.
                arr2[j] = i + s; // setting the messing number to i+s and store it in array2
                count++; // number of missing is incremented 
                s++; // increment the intial counter.
                j++;// increment index of array 
            }

                
        }
        s = arr[i] - i; //after each loop will set s to the difference between arr[index] and index/
    }
}
int main()
{

#ifndef ONLINE_JUDGE
    freopen("input", "rt", stdin);
#endif
#ifndef ONLINE_JUDGE
    freopen("output", "wt", stdout);
#endif

    int arr[array_size];
    int arr2[array_size2];
    for (int i = 0; i < array_size2; i++)
    {
        arr2[i] = -11000; // setting the value of array2 to invalid input to make sure i print only the missing number

    }

    for (int i = 0; i < 20; i++) // inserting imput array 
    {
        cin >> arr[i];
    }
    int count = 0; // setting the counts of missing numbers 
    FindandCountMissing(arr, arr2, array_size, count);

    if (count != 0)
    {
        cout << arr2[0];
        int j = 1;
        while (arr2[j] != -11000) // COUTing the array to the user and this condition is to make sure that i will only print the missing number 

        {
            cout << ' ' << arr2[j];
            j++;
        }
        cout << endl;
    }

    cout << count << endl;
}