#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../debugger/debug.h"
#else
#define debug(...) 420
#endif
using int64 = long long;
const int INF = (int)1e9;

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
  for (int i = 1; i <= x; i++) {
    dp[i] = INF;
    for (int j = 0; j < n; j++) {
      if (i - coins[j] >= 0) {
        dp[i] = min(dp[i], dp[i - coins[j]] + 1);
      }
    }
  }
  cout << (dp[x] == INF ? -1 : dp[x]) << '\n';
  return 0;
}