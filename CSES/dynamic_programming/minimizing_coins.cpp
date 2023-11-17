#include <bits/stdc++.h>
using namespace std;

using int64 = long long;
template<typename T>
bool ckmin(T& a, T b) { return b < a ? a = b, 1 : 0; }
template<typename T>
bool ckmax(T& a, T b) { return b > a ? a = b, 1 : 0; }
const int INF = (int)1e9;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int n, x;
  cin >> n >> x;
  vector<int> coins(n);

  for (int i = 0; i < n; i++) {
    cin >> coins[i];
  }
  vector<vector<int> > dp(n + 1, vector<int>(x + 1, INF));
  
  for (int i = 0; i <= n; i++) dp[i][0] = 0;

  for (int i = 0; i <= x; i++) dp[0][i] = 0;
  
  for (int i = 0; i < n + 1; i++) {
    for (int j = 0; j < x + 1; j++) {
      if (coins[i - 1] <= j) {
        dp[i][j] = min(1 + dp[i - 1][j - coins[i - 1]], dp[i - 1][j]);
      } else dp[i][j] = dp[i - 1][j];
    }
  }

  cout << dp[n][x] << '\n';
  return 0;
}