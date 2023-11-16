#include <bits/stdc++.h>
using namespace std;

using int64 = long long;
template<typename T>
bool ckmin(T& a, T b) { return b < a ? a = b, 1 : 0; }
template<typename T>
bool ckmax(T& a, T b) { return b > a ? a = b, 1 : 0; }
const int INF = (int)1e9;
// 1/0 knapsack problem mainy.
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, x;
  cin >> n >> x;
  vector<int> price(n);
  vector<int> pages(n);
  int min_price = INF;
  for (int i = 0; i < n; i++) cin >> price[i];
  for (int i = 0; i < n; i++) cin >> pages[i];

  vector<vector<int> > dp(n + 1, vector<int>(x + 1, INF));
  for (int i = 0; i <= n; i++) dp[i][0] = 0;
  for (int i = 0; i <= x; i++) dp[0][i] = 0;
  
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= x; j++) {
      if (price[i - 1] <= j) {
        dp[i][j] = max(pages[i - 1] + dp[i - 1][j - price[i - 1]], dp[i - 1][j]);
      } else dp[i][j] = dp[i - 1][j];
    }
  }
  cout << dp[n][x] << '\n';
  return 0;
}