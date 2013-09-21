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

typedef int _int;
typedef long long int64;
#define int int64

typedef pair<double, double> pdd;
typedef pair<int,  int>      pii;
typedef vector<double>       vd;
typedef vector<int>          vi;
typedef vector<vi>           vvi;

const double eps = 1e-11;
const double pi  = acos(-1.);
const int    p   = 1000000007;
int countbit(int n) { return n == 0 ? 0: countbit(n / 2) + n % 2; }
int lowbit  (int n) { return (n ^ (n-1) ) & n; }
int gcd(int a, int b) { return b == 0? a : gcd(b, a % b); }
int lcm(int a, int b) { return a * b / gcd(a, b); }
int toInt64(string s) { istringstream sin(s); int t; sin >> t; return t; }
string toStr (int t)  { stringstream sin; sin << t; string s; sin >> s; return s; }
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

int N = 20000+1;
vector<int> t(4*N + 100, 0);
int q = 1;

void update (int v, int tl, int tr, int l, int r, int add) {
	if (l > r)
		return;
	if (l == tl && tr == r)
		t[v] += add;
	else {
		int tm = (tl + tr) / 2;
		update (v*2, tl, tm, l, min(r,tm), add);
		update (v*2+1, tm+1, tr, max(l,tm+1), r, add);
	}
}

int get (int v, int tl, int tr, int pos) {
	if (tl == tr)
		return t[v];
	int tm = (tl + tr) / 2;
	if (pos <= tm)
		return t[v] + get (v*2, tl, tm, pos);
	else
		return t[v] + get (v*2+1, tm+1, tr, pos);
}

void solve() {
  int n;
  cin >> n;
  int s = 0;
  for (int i = 0; i < n; ++i) {
    int t;
    cin >> t;
    if (t == 1) {
      int a, x;
      cin >> a >> x;
      s += a*x;
      update(1, 0, N-1, 0, a-1, x);
    } else if (t == 2) {
      int k;
      cin >> k;
      s += k;
      ++q;
      update(1, 0, N-1, q-1, q-1, k);
    } else {
      int rm_val = get(1, 0, N-1, q-1);
      s -= rm_val;
      update(1, 0, N-1, q-1, q-1, -rm_val);
      --q;
    }
    printf("%.9f\n", static_cast<double>(s) / q);
  }
}


#define int int

int main() {
#ifndef ONLINE_JUDGE
  Timer timer;
#endif
  ios_base::sync_with_stdio(false);
#ifdef FILE_INPUT
  FILE* fin  = freopen("input.txt",  "r", stdin );
  FILE* fout = freopen("output.txt", "w", stdout);
#endif
  solve();
#ifdef FILE_INPUT
  fclose(fin);
  fclose(fout);
#endif
#ifndef ONLINE_JUDGE
  cout << endl << endl;
  timer.out();
#endif
  return EXIT_SUCCESS;
}

