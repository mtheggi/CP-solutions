#include<iostream>
using namespace std;
class Time{
private:

    int H ;
    int M ;
    int S ;

    public:
    Time(int h, int m, int s){

        H= h;
        M=m;
        S=s;

    }    

    void getTime(){
        cout << H << " " << M << " " << S << endl;
    }
};

    

int main(){
    Time v(1,2,3);

    v.getTime();


}