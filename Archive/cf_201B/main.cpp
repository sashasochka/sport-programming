#include <bits/stdc++.h>
using namespace std;
using vi = vector<string>;
using vvi = vector<vi>;

#define all(a) (a).begin(), (a).end()
#define pb push_back

/*
AJKEQSLOBSROFGZ
OVGURWZLWVLUXTH
OZ
 *
 * result: ORZ
 * my: GZ
 *
 *
ORZ
ORZ
OZ
 */
void solve() {
    string s1, s2, virus;
    cin >> s1 >> s2 >> virus;
    auto szcmp = [](string a, string b) {
      return a.size() < b.size();
    };
    vector<vvi> dp(s1.size() +1 , vvi(s2.size() + 1, vi(virus.size())));
    for (int i = 1; i <= s1.size(); ++i) {
        for (int j = 1; j <= s2.size(); ++j) {
            for (int k = 0; k < virus.size(); ++k) {
                auto c1 = s1[i-1], c2 = s2[j-1], v = virus[k];
                if (c1 == c2) {
                    if (c1 != v) {
                        dp[i][j][0] = max(dp[i-1][j-1][k] + c1, dp[i][j][0], szcmp);
                    } else {
                        int bad_syms = k + (c1 == v);
                        if (bad_syms != virus.size()) {
                            dp[i][j][bad_syms] = max(dp[i-1][j-1][k] + c1, dp[i][j][bad_syms], szcmp);
                        } else {
                            auto omg{dp[i-1][j][k], dp[i][j-1][k], dp[i][j][k]};
                            dp[i][j][k] = *max_element(all(omg), szcmp);
                        }
                    }
                } else {
                            auto omg{dp[i-1][j][k], dp[i][j-1][k], dp[i][j][k]};
                            dp[i][j][k] = *max_element(all(omg), szcmp);
                }
            }
        }
    }
    auto& bck = dp.back().back();
    auto result = *max_element(bck.begin(), bck.end(), szcmp);
    cout << (result.empty() ? "0" : result) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    solve();
    return EXIT_SUCCESS;
}

