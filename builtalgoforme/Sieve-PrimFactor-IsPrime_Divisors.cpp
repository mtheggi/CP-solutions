#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define el "\n"
using namespace std;
bool isPrime(int n)
{ // O(sqrt(n))
    if (n == 1)
        return false;
    bool Prime = true;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            Prime = false;
    }
    return Prime;
}
vector<int> divisors(int n)
{ // O(sqrt(n))
    vector<int> v;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            v.push_back(i);
            if (n / i != i)
                v.push_back(n / i);
        }
    }
    return v;
}
vector<int> primeFactorization(int n)
{ // O(sqrt(n))
    vector<int> v;
    for (int i = 2; i * i <= n; i++)
    {
        while (n % i == 0)
        {
            n /= i;
            v.push_back(i);
        }
    }
    if (n > 1)
        v.push_back(n);
    return v;
}
const int N = 101;
bool prime[N];
int spf[N]; // smallest Prime Factor
void sieve()
{ // O(n * (log(log(n)))
    memset(prime, true, sizeof prime);
    for (int i = 1; i < N; i++)
        spf[i] = i;
    prime[0] = prime[1] = false;
    for (int i = 2; i * i < N; i++)
    {

        for (int j = i + i; j < N; j += i)
        {
            prime[j] = false;
            spf[j] = min(spf[j], i);
        }
    }
}
vector<int> SievePrimeFactorization(int n)
{ // O(log(n))
    vector<int> v;
    while (n > 1)
    {
        v.push_back(spf[n]);
        n /= spf[n];
    }
    return v;
}

bool isBipartite(int V, vector<int> adj[])
{
    // vector to store colour of vertex
    // assigning all to -1 i.e. uncoloured
    // colours are either 0 or 1
    // for understanding take 0 as red and 1 as blue
    vector<int> col(V, -1);

    // queue for BFS storing {vertex , colour}
    queue<pair<int, int>> q;

    // loop incase graph is not connected
    for (int i = 0; i < V; i++)
    {

        // if not coloured
        if (col[i] == -1)
        {

            // colouring with 0 i.e. red
            q.push({i, 0});
            col[i] = 0;

            while (!q.empty())
            {
                pair<int, int> p = q.front();
                q.pop();

                // current vertex
                int v = p.first;
                // colour of current vertex
                int c = p.second;

                // traversing vertexes connected to current vertex
                for (int j : adj[v])
                {
                    // if already coloured with parent vertex color
                    // then bipartite graph is not possible
                    if (col[j] == c)
                        return 0;

                    // if uncoloured
                    if (col[j] == -1)
                    {
                        // colouring with opposite color to that of parent
                        col[j] = (c) ? 0 : 1;
                        q.push({j, col[j]});
                    }
                }
            }
        }
    }
    // if all vertexes are coloured such that
    // no two connected vertex have same colours
    return 1;
}
int main()
{
    /*Solution */
}
