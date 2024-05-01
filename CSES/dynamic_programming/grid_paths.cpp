#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "../debugger/debug.h"
#else
#define debug(...) 420
#endif

const int MOD = int(1e9 + 7);

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n;
  cin >> n;
  vector<vector<char>> grid(n, vector<char>(n));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> grid[i][j];

  vector<vector<int>> dp(n, vector<int>(n, 0));
  if (grid[0][0] != '*') dp[0][0] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i - 1 >= 0 && grid[i][j] != '*')
        dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
      if (j - 1 >= 0 && grid[i][j] != '*') 
        dp[i][j] = (dp[i][j] + dp[i][j - 1]) % MOD;
    }
  }
  cout << dp[n - 1][n - 1] << '\n';
  return 0;
}