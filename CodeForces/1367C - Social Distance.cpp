#include <bits/stdc++.h>
#define el "\n"
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

using namespace std;

int main()
{
    fastio;
#ifndef ONLINE_JUDGE
    freopen("input", "rt", stdin);
#endif
#ifndef ONLINE_JUDGE
    freopen("output", "wt", stdout);
#endif

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        s = "#" + s;
        int Cnt = 0;
        vector<int> prefix(n + 5, 0);
        vector<int> suffix(n + 5, 0);
        for (int i = n; i >= 1; i--)
        {
            suffix[i] = (s[i] - '0') + suffix[i + 1];
        }
        for (int i = 1; i <= n; i++)
        {
            if (s[i] == '1')
            {
                prefix[i] = 1 + prefix[i - 1];
            }
            else
            {
                int l = max(0, i - k - 1);
                int r = min(n + 1, i + k + 1);
                int lCnt = prefix[i - 1] - prefix[l];
                int rCnt = suffix[i + 1] - suffix[r];
                if (lCnt == 0 && rCnt == 0)
                {
                    prefix[i] = 1 + prefix[i - 1];
                    Cnt++;
                }
                else
                {
                    prefix[i] += prefix[i - 1];
                }
            }
        }
        cout << Cnt << endl;
    }
    //* ___________________________-another solution- ___________________
    /*
        int t ;
        cin >> t;
    while(t--){
        int i,j,n,k,ans=0;
        cin>>n>>k;
        string s;
        cin>>s;
        set<int> st;
        for(i=0;i<n;i++)
        {
            if(s[i]=='1')
            st.insert(i);
        }
        for(i=0;i<n;i++)
        {
            if(s[i]=='0')
            {
                auto it=st.lower_bound(i-k);
                if(it==st.end() or *it>i+k)
                {
                    ans++;
                    s[i]='1';
                    st.insert(i);
                }
            }
        }
        cout<<ans<<endl;


    }

    */

    return 0;
}