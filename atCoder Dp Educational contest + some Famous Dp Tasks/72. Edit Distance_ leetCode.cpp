#include <bits/stdc++.h>
using namespace std;
class Solution
{
    vector<vector<int>> dp;
public:
    Solution() : dp(550, vector<int>(550, -1)) {}

    int numberofedits(int x, int y, string w1, string w2)
    {
        if (x >= int(w1.size()))
            return (w2.size() - y);
        if (y >= int(w2.size()))
            return (w1.size() - x);

        int a = 1e7, b = 1e7, c = 1e7, d = 1e7;

        int &ret = dp[x][y];

        if (~ret) return ret; 

        if (w1[x] == w2[y]) return ret = numberofedits(x + 1, y + 1, w1, w2);
        else
        {
            b = 1 + numberofedits(x + 1, y, w1, w2);
            c = 1 + numberofedits(x, y + 1, w1, w2);
            d = 1 + numberofedits(x + 1, y + 1, w1, w2);
            return ret = min(b, min(c, d));
        }
    }

   
    int minDistance(string word1, string word2)
    {
        return numberofedits(0, 0, word1, word2);
    }
};