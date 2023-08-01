    #include<bits/stdc++.h>
    using namespace std;
    int n,a,x,y=100,b,c;
    main(){
    cin>>n;
    for(int i=0;i<n;i++){
       cin>>a;
       if(a>x){
        x=a;
        b=i;
       }
       if(a<=y){
        y=a;
        c=i;
       }
    }
    cout<<b+n-c-1-(c<b);
    }