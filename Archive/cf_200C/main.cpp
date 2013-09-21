#include <bits/stdc++.h>

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

vi pos;
vi need;

vpii resp;

int64 weight(int lrow, int rrow, int head) {
    auto d1 = abs(pos[head] - need[lrow]);
    auto d2 = abs(pos[head] - need[rrow]);
    if ((lrow <= pos[head]) == (rrow <= pos[head])) {
        return max(d1, d2);
    } else {
        return 2 * min(d1, d2) + max(d1, d2);
    }
}

void solve() {
    int64 n, m;
    cin >> n >> m;
    pos.resize(n);
    resp.resize(n);
    need.resize(m);
    for (auto& val : pos) {cin >> val; val --; }
    for (auto& val : need) {cin >> val; val --; }
    for (auto& val : resp) { val = {m, m};}
    priority_queue<pii> pq; // weight, head index
    pq.push({weight(0, m - 1, 0), 0});
    while (true) {
        int wght, head;
        tie(wght, head) = pq.top();
        pq.pop();
    }

}

int main() {
    ios::sync_with_stdio(false);
    solve();
    return EXIT_SUCCESS;
}

