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

int n, m;
vvi old_neigh, new_neigh;

bool can(int a, int b) {
    if (a == b) return false;
    for (int val: old_neigh[a])
        if (val == b)
            return false;
    for (int val: new_neigh[a])
        if (val == b)
            return false;
}

inline void solve() {
    cin >> n >> m;
    old_neigh.assign(n);
    new_neigh.assign(n);
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        old_neigh[a].pb(b);
        old_neigh[b].pb(a);
    }
    list<int> group2, group1, group0;
    for (int i = 0; i < n; ++i) {
        if (old_neigh[i].size() == 2)
            group2.pb(i);
        else if (old_neigh[i].size() == 2)
            group1.pb(i);
        else group0.pb(i);
    }

    int edges = 0;
    for (auto it = group2.begin(); it != group2.end(); ) {
        auto jt = it;
        bool ok = false;
        for (++jt; jt != group2.end(); ++jt) {
            if (can(*it, *jt)) {
                new_neigh[*it].pb(*jt);
                new_neigh[*jt].pb(*it);
                group1.pb(*it);
                group1.pb(*jt);
                group2.erase(jt);
                it = group2.erase(it);
                ok = false;
                ++edges;
                if (edges == m) goto finish;
                break;
            }
        }
        if (!ok) ++it;
    }

    finish:
    for (int i = 0; i < n; ++i) {
        for (int neigh: new_neigh[i]) {
            if (neigh > i) {
                cout << i << ' ' << neigh << endl;
            }
        }
    }

}

int main() {
    cout.sync_with_stdio(false);
    cin.sync_with_stdio(false);
    solve();
    return EXIT_SUCCESS;
}

