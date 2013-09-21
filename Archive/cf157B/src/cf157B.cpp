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
int countbit(int n){return n == 0 ? 0: countbit(n / 2) + n % 2;}
int lowbit  (int n){return (n ^ (n-1) ) & n;}
int64 gcd(int64 a, int64 b){ return b == 0? a : gcd(b, a % b);}
int64 lcm(int64 a, int64 b){ return a * b / gcd(a, b);}
int64 toInt64(string s){ istringstream sin(s); int64 t; sin >> t; return t;}
string toStr(int64 t)  { stringstream sin; sin << t; string s; sin >> s; return s;}
template<typename T> T sqr(T n){return n * n;}
template<typename T> void out(T& v){for(int i = 0; i < v.size(); i++) cout << v[i] << ' '; cout << endl;}

#define all(a)  (a).begin(), (a).end()
#define pb      push_back

class Timer
{
public:
    double start;
    Timer(){start = static_cast<double>(clock());}
    void out(){ cout << "TIME: " << (clock() - start) / CLOCKS_PER_SEC << endl;}
};


//#define FILE_INPUT

vector<vector<int> > sq(3, vector<int>(3));

void solve() {
  for (int i = 0; i < 3; ++i)
    for (int j = 0; j < 3; ++j)
      cin >> sq[i][j];
  for (int i = 1; i<= 300000; ++i) {
    int v1 = i - sq[0][1] - sq[0][2];
    int v2 = i - sq[1][0] - sq[1][2];
    int v3 = i - sq[2][0] - sq[2][1];
    if (v1 + v2 + v3 == i) {
      sq[0][0] = v1;
      sq[1][1] = v2;
      sq[2][2] = v3;
      for(int m = 0; m < 3; m ++ )
        for(int n = 0; n < 3; n++)
          cout<<sq[m][n]<<(n == 2 ? '\n' : ' ');
      return;
    }
  }
}




int main(){
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

