#include <bits/stdc++.h>
#define el "\n"
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL)

using namespace std;
#define ll long long
int const N = 1e7 +6  ;
char Ns[10] = {'0','1','2','3','4','5','6','7','8','9'};
string sum(string str1 , string str2){

    int n1 = str1.size();
    string s= "";
    int carry =0 ;
    int num =0;
    for (int i=n1-1 ; i >=0 ; --i){
        int c = (str1[i]-'0') + (str2[i]- '0') + carry;
            num= c%10 ;
            carry = c/10;
            s.push_back(Ns[num]);
    }
    reverse(s.begin(),s.end());
return s ;

}
int main()
{
    fastio;
    int t ;
    cin >> t ;
    while(t--){
        int n ; cin >> n ;
        string s ;
        cin >> s ;
        string str1 ,str2;

        if(s[0] != '9'){
            for (int i = 0; i <n ; ++i) {
                int c  = '9' - s[i];
                    cout <<c;

            }
            cout<<endl;
        }else {
            for (int i = 0; i <n; ++i) {
                int c  = '9' - s[i];
                    str1.push_back(Ns[c] );

            }
            for (int i = 0; i < n; ++i) {
                if(i == n-1 ){
                    str2.push_back('2');
                    continue;
                }
                str2.push_back('1');
            }
            string s = sum(str1 ,str2 );

            cout << s <<endl;
        }
    }



    return 0 ;
}
