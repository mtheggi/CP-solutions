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
    int rev = 0;
    deque<int> q;
    string s;
    int n, t;
    cin >> n;
    while (n--)
    {
        cin >> s;
        if (s == "reverse")
        {
            rev++;
        }
        else if (s == "front")
        {
            if (rev % 2 == 0)
            {
                if (!q.empty())
                {
                    cout << q.front() << el;
                    q.pop_front();
                }
                else
                {
                    cout << "No job for Ada?" << el;
                }
            }else{
                 if (!q.empty())
                {
                    cout << q.back() << el;
                    q.pop_back();
                }
                else
                {
                    cout << "No job for Ada?" << el;
                }
            }
        }
        else if (s == "back")
        {
            if (rev % 2 == 0)
            {
                if (!q.empty())
                {
                    cout << q.back() << el;
                    q.pop_back();
                }
                else
                {
                    cout << "No job for Ada?" << el;
                }
            }else{
                 if (!q.empty())
                {
                    cout << q.front() << el;
                    q.pop_front();
                }
                else
                {
                    cout << "No job for Ada?" << el;
                }
            }
        }
        else if (s == "toFront")
        {       cin >>t ;
            if(rev %2 == 0){
                q.push_front(t); 
            }else {
                q.push_back(t);
            }
        }
        else if (s == "push_back")
        {

            cin >>t ;
            if(rev %2 == 0){
                q.push_back(t); 
            }else {
                q.push_front(t);
            }
        }
    }

    return 0;
}
