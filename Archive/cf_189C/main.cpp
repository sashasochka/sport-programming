#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

typedef unsigned long long uint64;

const uint64 p = 1000000007;
void solve() {
    string x;
    cin >> x;
    uint64 n = x.size();
    uint64 ones = count(x.begin(), x.end(), '1');
    uint64 zeros = n - ones;
    if (ones == 0) {
        cout << 0 << endl;
        return;
    }
    uint64 result = 1;
    int k = 1;
    bool o = true;
    for (uint64 i = 0; i < n; ++i) {
        if (x[i] == '0') {
            for (int j = 0; j < k; ++j)
                result = (result * 2) % p;
            o = true;
        } else {
            if (o) {
                k++;
                o = false;
            }
        }
    }
    uint64 _2n = 1;
    for (uint64 i = 0; i < ones - 1; ++i) {
        _2n = (2 * _2n) % p;
    }
    result = (result * _2n) % p;
    result = (result * ((2 * _2n -1) % p)) % p;
    cout << result << endl;
}




int main() {
    solve();
    return EXIT_SUCCESS;
}

