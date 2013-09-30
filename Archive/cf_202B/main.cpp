#include <bits/stdc++.h>
#include <climits>
using namespace std;

using int64 = long long;
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

void dfs(int root);
vvi tree;
vi is_leaf, a;
auto result = 0ll;
    int n;
void solve() {
    cin >> n;
    a.resize(n); for (auto& val:a) cin >> val;
    vvi pretree(n);
    for (int i = 0; i < n - 1; ++i) {
        int x, y;
        cin >> x >> y;
        --x;
        --y;
        pretree[x].pb(y);
        pretree[y].pb(x);
    }

    vi visited(n);
    tree.resize(n);
    is_leaf.resize(n);
    stack<int> st; st.push(0);
    visited[0] = true;
    while (!st.empty()) {
        auto cur = st.top();
        st.pop();
        bool leaf = true;
        for (auto neighb: pretree[cur]) {
            if (!visited[neighb]) {
                visited[neighb] = true;
                st.push(neighb);
                tree[cur].pb(neighb);
                leaf = false;
            }
        }
        if (leaf) is_leaf[cur] = true;
    }

    dfs(0);
    cout << result << endl;
}

void dfs(int root) {
    if (is_leaf[root]) {
        return;
    }
    for (auto neighb: tree[root]) dfs(neighb);
    int64 val = LLONG_MAX;
    auto mxchild = 1ll;
    for (auto neighb: tree[root]) {
        val = min(val, a[neighb]);
        mxchild = lcm(mxchild, max((int64)tree[neighb].size(), 1ll));
        if (mxchild > 10000) {
            auto result = 0ll;
            for (auto i = 0; i < n; ++i) {
                if (is_leaf[i]) {
                    result += a[i];
                }
            }
            cout << result << endl;
            exit(0);
        }
    }
    val = mxchild * (val / mxchild);
    a[root] = tree[root].size() * val;
    for (auto neighb: tree[root]) {
        result += (a[neighb] - val);
    }

}

int main() {
    ios::sync_with_stdio(false);
    solve();
    return EXIT_SUCCESS;
}

