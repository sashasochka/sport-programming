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
#include <vector>

using namespace std;

typedef long long            int64;
typedef pair<double, double> pdd;
typedef pair<int,  int>      pii;
typedef pair<int64,int64>    pii64;
typedef unsigned long long   uint64;
typedef vector<double>       vd;
typedef vector<int64>        vi64;
typedef vector<int>          vi;
typedef vector<vi>           vvi;

const double eps = 1e-11;
const double pi  = acos(-1.0);
const int    p   = 1000000007;
int countbit(int n) { return n == 0 ? 0: countbit(n / 2) + n % 2; }
int lowbit  (int n) { return (n ^ (n-1) ) & n; }
int64 gcd(int64 a, int64 b){ return b == 0? a : gcd(b, a % b); }
int64 lcm(int64 a, int64 b){ return a * b / gcd(a, b); }
int64 toInt64(string s) { istringstream sin(s); int64 t;        sin >> t; return t; }
string toStr (int64 t)  { stringstream sin; sin << t; string s; sin >> s; return s; }
template<typename T> T sqr(T n){ return n * n; }
template<typename T> void out(T& v){
   for(int i = 0; i < v.size(); i++) cout << v[i] << (i == v.size() - 1? '\n' : ' ');
}

#define all(a)  (a).begin(), (a).end()
#define pb      push_back

class Timer {
 public:
  double start;
  Timer(){ start = static_cast<double>(clock()); }
  void out(){ cout << "TIME: " << (clock() - start) / CLOCKS_PER_SEC << endl; }
};


//#define FILE_INPUT
/*const int64 MAXN = 10001;
int64 n, m, h[MAXN], t[4*MAXN], s[4*MAXN];

void build (int64 a[], int64 v = 1, int64 tl = 0 , int64 tr = n-1) {
	if (tl == tr) {
		t[v] = a[tl];
    s[v] = -1;
  }
	else {
		int64 tm = (tl + tr) / 2;
		build (a, v*2, tl, tm);
		build (a, v*2+1, tm+1, tr);
		t[v] = max(t[v*2], t[v*2+1]);
    s[v] = -1;
	}
}

void push (int64 v) {
	if (s[v] != -1) {
		t[v*2] = t[v*2+1] = t[v];
		s[v] = -1;
    s[v*2] = s[v*2+1] = 0;
	}
}


int64 query (int64 v, int64 tl, int64 tr, int64 l, int64 r) {
	if (l > r)
		return 0;
	if (l == tl && r == tr)
		return t[v];
	int64 tm = (tl + tr) / 2;
  push(v);
	return max(query (v*2, tl, tm, l, min(r,tm))
		, query (v*2+1, tm+1, tr, max(l,tm+1), r));
}

void update (int64 v, int64 tl, int64 tr, int64 l, int64 r, int64 color) {
	if (l > r)
		return;
	if (l == tl && tr == r) {
		t[v] = color;
    s[v] = 0;
  }
	else {
		push (v);
    s[v] = -1;
		int64 tm = (tl + tr) / 2;
		update (v*2, tl, tm, l, min(r,tm), color);
		update (v*2+1, tm+1, tr, max(l,tm+1), r, color);
	}
}
*/

void solve() {
  int n,m;
  cin >> n;
  vector<int64> v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];
  cin >> m;
  int64 H = 0, W = 0;
  for (int i = 0; i < m; i ++) {
    int64 w, h;
    cin >> w >> h;
    int64 s = H;
    for (int j = W; j < w; j++)
      s = max(s, v[j]);
    cout << s << endl;
    W = max(W, w);
    H = max(H, s + h);
  }

}




int main() {
#ifndef ONLINE_JUDGE
  Timer timer;
#endif
#ifdef FILE_INPUT
  freopen("input.txt",  "r", stdin );
  freopen("output.txt", "w", stdout);
#endif
  cout.sync_with_stdio(false);
  cin. sync_with_stdio(false);
  solve();
#ifdef FILE_INPUT
  fclose(stdin);
  fclose(stdout);
#endif
#ifndef ONLINE_JUDGE
  cout << endl << endl;
  timer.out();
  cin.get();
#endif
  return EXIT_SUCCESS;
}

