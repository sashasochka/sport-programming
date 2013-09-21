#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

typedef long long int64;
typedef unsigned long long uint64;
typedef pair<int64, int64> pii;
typedef pair<double, double> pdd;
typedef vector<int64> vi;
typedef vector<pii> vpii;
typedef vector<double> vd;
typedef vector<vi>  vvi;

constexpr double eps = 1e-11;
constexpr double pi = acos(-1.0);
constexpr int64 p = 1000000007;
constexpr int64 countbit(int64 n) { return n == 0 ? 0: countbit(n / 2) + n % 2; }
constexpr int64 lowbit(int64 n) { return (n ^ (n-1) ) & n; }
constexpr int64 gcd(int64 a, int64 b) { return b == 0? a : gcd(b, a % b); }
constexpr int64 lcm(int64 a, int64 b) { return a * b / gcd(a, b); }
int64 toInt64(string s) { istringstream sin(s); int64 t; sin >> t; return t; }
string toStr(int64 t) { stringstream sin; sin << t; string s; sin >> s; return s; }
template<typename T> constexpr auto sqr(const T& n) -> decltype(n * n) { return n * n; }
template<typename T> void out(const T& array) {
   for(const T& value : array) cout << value << "\n";
   cout.flush();
}

struct Point {
    int64 x;
    int64 y;
    Point(){}
    Point(int x, int64 y): x(x), y(y){}
    bool operator<(const Point& that) const {
        return make_pair(x,y) < make_pair(that.x, that.y);
    }
};

#define all(a) (a).begin(), (a).end()
#define pb push_back

vector<bool> erato(50000, true);

bool isSquare(int64 k) {
    int64 sq = sqrt(k);
    return sq * sq == k;
}

void solve() {
    int n;
    cin >> n;
    erato[0] = erato[1] = false;
    for (int cur = 2; cur <= 40000; ++cur) {
        if (!erato[cur]) continue;
        for (int vcur = cur * 2; vcur <= erato.size(); vcur += cur)
            erato[vcur] = false;
    }
    vi primes;
    for (int i = 2; i < erato.size(); ++i)
        if (erato[i])
            primes.pb(i);
    vector<bool> result(erato.size(), false);
    for (int p1 : primes)
        for (int p2: primes)
            if (isSquare(p1 * p2 + 1))
                if (int(sqrt(p1 * p2 + 1)) < result.size())
                    result[sqrt(p1 * p2 + 1)] = true;
    for (int i = 0; i <= n; ++i) {
        if (result[i])
            cout << i << endl;
    }

}

int main() {
    cout.sync_with_stdio(false);
    cin.sync_with_stdio(false);
    solve();
    return EXIT_SUCCESS;
}

