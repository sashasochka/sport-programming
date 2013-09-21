#include <bits/stdc++.h>
using namespace std;

using int64 = int64_t;
using uint64 = uint64_t;
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
template<typename T> constexpr auto sqr(const T& n) -> decltype(n * n) { return n * n; }

template<typename T>
struct Point {
    T x; T y;
    constexpr Point() noexcept(T()) : x{}, y{} {}
    constexpr Point(const T x, const T& y) noexcept(noexcept(T(T()))): x{x}, y{y} {}
    constexpr bool operator<(const Point<T>& that) const {
        return x < that.x || (x == that.x && y < that.y);
    }
};
using Pt = Point<int64>;

#define all(a) (a).begin(), (a).end()
#define pb push_back

int64 GCD(int64 a, int64 b) {
    if (b == 0) return a;
    else return GCD(b, a % b);
}

void solve() {
    int n; cin >> n;
    vi v(n); for (auto& val: v) cin >> val;
    auto gcd = accumulate(v.begin(), v.end(), v.front(), GCD);
    for (auto &val : v) val /= gcd;
    auto mx = *max_element(v.begin(), v.end());
    cout << ((mx - n) % 2 == 1 ? "Alice" : "Bob");
}

int main() {
    ios::sync_with_stdio(false);
    solve();
    return EXIT_SUCCESS;
}

