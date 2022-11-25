    #include<iostream>
    using namespace std;
    int main()
    {
    int x,a,b,z=0;
    cin>>x;
    for(int i=0;i<x;i++)
    {
    cin>>a>>b;
    if((b-a) >= 2)
    z++;
    }
    cout<<z<<endl;
    }