#include <stdio.h>
void passbyvalue(int value);
void passbyref(int &ref);
void passbyptr(int *ptr);
int main()
{
    int example[5];

    int x = 5;
    printf("x = %i\n", x);
    passbyvalue(x);
    printf("x = %i\n", x);
    // * -------- ref --------

    passbyref(x);
    printf("x = %i\n", x);
    // * -------- pointer --------
    printf("**************pointers***************\n");
     int *xptr = &x;
    printf(" x = %i\n", x);
    printf(" *xptr = %i\n", *xptr);
    passbyptr(xptr);
    printf(" x = %i\n", x);
    printf(" *xptr = %i\n", *xptr);
    printf("index 0 of example -= %i\n", example[0]); 

    return 0;
}
void passbyvalue(int value) // ! making a copy of the arg. and modified it.
{
    value = 10;
    value = 10;
    printf("value = %i\n", value);
}
void passbyref(int &ref)
{
    ref = 20;
    printf("ref= %i\n", ref);
}
void passbyptr(int *ptr)
{
    *ptr = 30;
    printf("ptr= %i\n", *ptr);
}
