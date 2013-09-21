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

void solve() {
    int needVal;
    cin >> needVal;
    string haveStr;
    cin >>  haveStr;
    vi have(10);
    for (auto c: haveStr)
        ++have[c-'0'];

    string needStr = toStr(needVal);
    replace(all(needStr), '5', '2');
    replace(all(needStr), '9', '6');
    have[6] += have[9]; have[9] = 0;
    have[2] += have[5]; have[5] = 0;
    vi need(10);
    for (auto c: needStr)
        need[c-'0']++;
    need[6] += need[9]; need[9] = 0;
    need[2] += need[5]; need[5] = 0;
    int64 result = p;
    for (auto curVal = 0; curVal != need.size(); ++curVal) {
        if (need[curVal]) {
            result = min(result, have[curVal] / need[curVal]);
        }
    }
    cout << result <<endl;
}

int main() {
    cout.sync_with_stdio(false);
    cin.sync_with_stdio(false);
    solve();
    return EXIT_SUCCESS;
}

