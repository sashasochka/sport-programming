#pragma comment(linker, "/STACK:256000000")
#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <bitset>
#include <cmath>
#include <list>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <fstream>
#include <map>
#include <ctime>
#include <functional>
#include <numeric>

using namespace std;
 
typedef long long            int64;
typedef unsigned long long   uint64;
typedef pair<int,  int>      pii;
typedef pair<int64,int64>    pii64;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vi> vvi;
typedef vector<int64> vi64;

const double pi  = acos(-1.0);
const double eps = 1e-11;
const int    p   = 1000000007;
int countbit(int n){return n == 0 ? 0: countbit(n / 2) + n % 2;}
int lowbit  (int n){return (n ^ (n-1) ) & n;}
int64 gcd(int64 a, int64 b){ return b == 0? a : gcd(b, a % b);}
int64 lcm(int64 a, int64 b){ return a * b / gcd(a, b);}
int64 toInt64(string s){ istringstream sin(s); int64 t; sin >> t; return t;}
string toStr(int64 t)  { stringstream sin; sin << t; string s; sin >> s; return s;}
template<typename T> T sqr(T n){return n * n;}
template<typename T> void out(T& v){for(int i = 0; i < v.size(); i++) cout << v[i] << ' '; cout << endl;}
 
#define pb      push_back
#define all(a)  (a).begin(), (a).end()

class Timer
{
public:
  double start;
  Timer(){start = static_cast<double>(clock());}
  void out(){ cout << "TIME: " << (clock() - start) / CLOCKS_PER_SEC << endl;}
};


//#define LocalHost

void solve()
{
  ifstream fin("input.txt");
  ofstream fout("output.txt");
  
  int n;
  fin >> n;
  
  vi a(n + 1);
  for(int i = 1; i <= n; i++)
    fin >> a[i];
  
  int R1,C1, R2,C2;
  fin >> R1 >> C1 >> R2 >> C2;
  
  int result = p;
  
  for(int i = 1; i <= n; i++)
  {
    int res = 0;
    int r1 = R1, r2 = R2, c1 = C1, c2 = C2;
    while(r1 < i)
    {
      r1++;
      c1 = min(c1, a[r1] + 1);
      res++;
    }
    while(r1 > i)
    {
      r1--;
      c1 = min(c1, a[r1] + 1);
      res++;
    }
    
    while(r1 < r2)
    {
      r1++;
      c1 = min(c1, a[r1] + 1);
      res++;
    }
    while(r1 > r2)
    {
      r1--;
      c1 = min(c1, a[r1] + 1);
      res++;
    }
    res += abs(c1 - c2);
    
    result = min(result, res);
  }
  fout << result << endl;
}




int main(){
#ifdef LocalHost
  Timer timer;
#endif
  cout.sync_with_stdio(false);
  cin. sync_with_stdio(false);
  solve();
#ifdef LocalHost
  cout << endl << endl;
  timer.out();
  cin.get();
#endif
  return EXIT_SUCCESS;
}

