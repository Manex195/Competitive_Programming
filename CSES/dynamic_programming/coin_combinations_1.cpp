#include <bits/stdc++.h>
using namespace std;
 
#ifdef LOCAL
#include "../debugger/debug.h"
#else
#define debug(...) 420
#endif
using int64 = long long;
const int MOD = int(1e9 + 7);
 
// for file input/output.
// void setIO(string fName) {
//   freopen((fName + ".in").c_str(), "r", stdin);
//   freopen((fName + ".out").c_str(), "w", stdout);
// }
 
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
  for (int i = 1; i <= x; i++) {
    for (int j = 0; j < n; j++) {
      if (i - coins[j] >= 0) {
        dp[i] = (dp[i] + dp[i - coins[j]]) % MOD;
      }
    }
  }
  cout << dp[x] << '\n';
  return 0;
