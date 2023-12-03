#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../debugger/debug.h"
#else
#define debug(...) 420
#endif
using int64 = long long;

// for file input/output.
// void setIO(string fName) {
//   freopen((fName + ".in").c_str(), "r", stdin);
//   freopen((fName + ".out").c_str(), "w", stdout);
// }
const int MOD = (int)1000000007;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, x;
  cin >> n >> x;
  vector<int> coins(n);
  for (int i = 0; i < n; i++) {
    cin >> coins[i];
  }
  vector<int> dp(x + 1);
  dp[0] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 1; j <= x; j++) {
      if (coins[i] <= j) {
        dp[j] = (dp[j] + dp[j - coins[i]]) % MOD;
      }
    }
  }
  cout << dp[x] << '\n';
  return 0;
}