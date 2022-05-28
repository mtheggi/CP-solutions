    #include <bits/stdc++.h>
    //#include<iomanip>
    using namespace std;
    typedef long long ll;
     
     
     
     
    int main()
    {
        int t;
        cin>>t;
        while(t--)
        {
           int n;
           cin>>n;
           ll a[n];
           for(int i=0;i<n;i++)cin>>a[i];
           sort(a,a+n);
           int ans=0;
           for(int i=1;i<n;i++)a[i]+=a[i-1];
           for(int i=1;i<=n/2;i++){
     
            if(a[i]<a[n-1]-a[n-i-1]){ans=1;break;}
           }
           if(ans)cout<<"YES"<<endl;
           else cout<<"NO"<<endl;
        }
    }