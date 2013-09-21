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

vector<vector<char>> map;
int64 n, m, sX, sY, eX, eY;

bool valid(int y, int x) {
    return 0 <= y && y < n && 0 <= x && x < m && map[y][x] != 'T';
}

inline void solve() {
    cin >> n >> m;
    map.assign(n, vector<char>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char c;
            cin >> c;
            map[i][j] = c;
            if (c == 'S') {
                sY = i;
                sX = j;
            } else if (c == 'E') {
                eY = i;
                eX = j;
            } else if (c != 'T') {
                map[i][j] -= '0';
            }
        }
    }
    vvi dist(n, vi(m, p));
    dist[eY][eX] = 0;
    queue<pii> q;
    q.push(make_pair(eY, eX));
    while (!q.empty()) {
        pii cur = q.front();
        q.pop();
        for (int dy = -1; dy <= 1; ++dy)  {
            for (int dx = -1; dx <= 1; ++dx) {
                if (abs(dy) + abs(dx) == 1) {
                    int nY = cur.first + dy;
                    int nX = cur.second + dx;
                    if (valid(nY, nX) && dist[nY][nX] == p) {
                        dist[nY][nX] = dist[cur.first][cur.second] + 1;
                        q.push(make_pair(nY, nX));
                    }
                }
            }
        }
    }
    int myD = dist[sY][sX];
    int result = 0;
    for (int i = 0 ; i < n; ++i) {
        for (int j = 0; j < m; ++j ) {
            if (map[i][j] < 10 && dist[i][j] <= myD) {
                result += map[i][j];
            }
        }
    }
    cout << result << endl;
}

int main() {
    cout.sync_with_stdio(false);
    cin.sync_with_stdio(false);
    solve();
    return EXIT_SUCCESS;
}

