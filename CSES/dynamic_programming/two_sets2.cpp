#include <bits/stdc++.h>
using namespace std;

using int64 = long long;
template<typename T>
bool ckmin(T& a, T b) { return b < a ? a = b, 1 : 0; }
template<typename T>
bool ckmax(T& a, T b) { return b > a ? a = b, 1 : 0; }

// for file input/output.
// void setIO(string fName) {
//   freopen((fName + ".in").c_str(), "r", stdin);
//   freopen((fName + ".out").c_str(), "w", stdout);
// }
const int MOD = (int)1000000007;

int64 subset_sum(int n, int trg) {
  vector<vector<int>> dp(n + 1, vector<int>(trg + 1));

  for (int i = 0; i <= n; i++) dp[i][0] = 1;
  for (int i = 0; i <= trg; i++) dp[0][i] = 0;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= trg; j++) {
      if (i <= j) {
        dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - i]) % MOD;
      } else {
        dp[i][j] = dp[i - 1][j];
        dp[i][j] %= MOD;
      }
    }
  }
  return dp[n][trg];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  int64 total_sum = (1LL * (n * (n + 1)) / 2);
  if (total_sum & 1) {
    cout << 0 << '\n';
  } else {
    int64 _sets = subset_sum(n, total_sum / 2);
    cout << _sets << '\n';
  }
  return 0;
}