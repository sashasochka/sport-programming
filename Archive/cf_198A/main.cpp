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

using int64 = long long;
using uint64 = unsigned long long ;
using pii = pair<int64, int64>;
using pdd = pair<double, double>;
using vi = vector<int64>;
using vpii = vector<pii>;
using vd = vector<double>;
using vvi = vector<vi>;

constexpr double eps = 1e-11;
constexpr double pi = acos(-1.0);
constexpr int64 p = 1000000007;
constexpr int64 countbit(int64 n) { return n == 0 ? 0 : countbit(n / 2) + n % 2; }
constexpr int64 lowbit(int64 n) { return (n ^ (n-1) ) & n; }
constexpr int64 gcd(int64 a, int64 b) { return b == 0? a : gcd(b, a % b); }
constexpr int64 lcm(int64 a, int64 b) { return a * b / gcd(a, b); }
int64 toInt64(string s) { istringstream sin(s); int64 t; sin >> t; return t; }
template<typename T> constexpr auto sqr(const T& n) -> decltype(n * n) { return n * n; }
template<typename T> void out(const T& array, ostream& stream = cout) {
   for(const T& value : array) stream << value << "\n";
   stream.flush();
}

struct Point {
    int64 x = 0;
    int64 y = 0;
    Point() {}
    Point(int64 x, int64 y): x{x}, y{y} {}
    bool operator<(const Point& that) const noexcept {
        return make_pair(x, y) < make_pair(that.x, that.y);
    }
};

#define all(a) (a).begin(), (a).end()
#define pb push_back

inline void solve() {
    int n;
    cin >> n;
    vi v(n), first(n + 1), last(n + 1);
    for (int i = 0 ; i < n; ++ i) {
        cin >> v[i];
    }
    first[0] = 0;
    last[0] = 0;
    for (int i = 0; i < n; ++i) {
        first[i + 1] = first[i] + v[i];
        last[i + 1] = last[i] + v[n - i - 1];
    }
    int64 res = 0;
    for (int i = 0; i < n; ++i) {
        res += (i * v[i]) - first[i - 1];
    }
    for (int i = 0; i < n - 1; ++i) {
        res += last[n - i - 2] - (n - i - 1) * v[i];
    }
    cout << res << endl;
}

int main() {
    ios::sync_with_stdio(false);
    solve();
    return EXIT_SUCCESS;
}

