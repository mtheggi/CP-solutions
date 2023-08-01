    #include <bits/stdc++.h>
    using namespace std;
    const int N = 1e5 + 5;
    #define ll long long
    #define ld long double
    #define el "\n"
    // transform number into binary
    string to_binary(int n){
        string s;
        while (n){
            int rem = n % 2;
            s.push_back(char(rem + '0'));
            n /= 2;
        }
        reverse(s.begin(), s.end());
        return s;
    }
    // multiply x by 2 i times
    int shift_left(int x, int i){
        return x << i;
    }
    // divide x by 2 i times
    int shift_right(int x, int i){
        return x >> i;
    }
    // set ith bit
    int addIthBit(int x, int i){
        return x | (1 << i);
    }
    // unset ith bit
    int removeIthBit(int x, int i){
        return x & (~(1 << i));
    }
    // check the existence of the bit
    bool checkBit(int x, int i){
        return x & (1 << i);
    }
    // Flipping the ith bit
    int flipBit(int x, int i){
        return x ^ (1 << i);
    }
    // get the least significant bit
    int LSB(int x){
        return x & (-x);
    }
    // get the most significant bit
    int MSB(int x){
        int msb = 0;
        while (x){
            x >>= 1;
            msb++;
        }
        return msb - 1;
    }
    bool checkPowerOfTwo(int x){
        return !(x & (x - 1));
    }
    int main() {
        // O((2 ^ n) * n)
        // output all possible subsets of the array using BitMasking
        int n;
        cin >> n;
        vector<int> a(n + 2);
        for(int i = 0; i < n; i++) cin >> a[i];
        int limit = (1 << n) - 1;
        for(int msk = 0; msk <= limit; msk++){
            for(int i = 0; i < 3; i++){
                if(checkBit(msk, i)){
                    cout << a[i] << " ";
                }
            }
            cout << el;
        }
        return 0;
    }
     
     
     