#include<iostream>
int main (){
    int a,b ;
    std :: cin>> a >> b ;
    int x = std::max(a,b); 
    switch(7-x)
   {
    case 1: std::cout << "1/6" << std::endl; break;
    case 2: std::cout << "1/3" << std::endl; break;
    case 3: std::cout << "1/2" << std::endl; break;
    case 4: std::cout << "2/3" << std::endl; break;
    case 5: std::cout << "5/6" << std::endl; break;
    case 6: std::cout << "1/1" << std::endl; break;
   }
}
 // ! another solution forim github.
/*

#include <iostream>
#include <string>

using namespace std;

int main()
{
   int Y, W;
   cin >> Y >> W;

   const string probability[7] = {"", "1/1", "5/6", "2/3", "1/2", "1/3", "1/6"};
   int D = max(Y, W);
   cout << probability[D] << endl;
   return 0;
}


*/