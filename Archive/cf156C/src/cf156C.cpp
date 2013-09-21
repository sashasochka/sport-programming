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

void solve()
{
  int n;
  cin >> n;
  vi b(n);
  vvi pos(1000001);
  for(int i = 0; i < n; ++i)
  {
    cin >> b[i];
    pos[b[i]].pb(i);
  }
  int result = 0;
  vector<bool> tested(pos.size());
  for(int i = 0; i < n; ++i)
    if(!tested[b[i]])
    {
      for(int j = i + 1; j < n; ++j)
        if(b[i] != b[j])
        {
          int l1 = b[i], l2 = b[j];
          int res = 1;
          bool first = false;
          int cur_pos = i;
          int p1 = 1;
          int p2 = 0;
          while(true)
          {
            if(!first)
            {
              while(p2 < (int)pos[l2].size() && pos[l2][p2] < cur_pos)
                p2++;
              if(p2 >= (int)pos[l2].size()) break;
              cur_pos = pos[l2][p2];
            }
            else
            {
              while(p1 < (int)pos[l1].size() && pos[l1][p1] < cur_pos)
                p1++;
              if(p1 >= (int)pos[l1].size()) break;
              cur_pos = pos[l1][p1];
            }
            res++;
            first = !first;
          }

          result = max(res, result);
        }
      tested[b[i]] = true;
    }
  for(int i = 0; i < (int)pos.size(); i++)
    result = max(result, (int)pos[i].size());
  cout << result << endl;
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

