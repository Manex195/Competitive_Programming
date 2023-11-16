#include <bits/stdc++.h>
using namespace std;

using int64 = long long;
template<typename T>
bool ckmin(T& a, T b) { return b < a ? a = b, 1 : 0; }
template<typename T>
bool ckmax(T& a, T b) { return b > a ? a = b, 1 : 0; }
const int64 mod = int64(1e9 + 7);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int64> dp(n + 1);
  dp[0] = 1, dp[1] = 1;
  for (int i = 2; i <= n; i++) {
    for (int j = 1; j <= 6 && (i < 6 ? j <= i : j <= 6); j++) {
      dp[i] = (0LL + dp[i] + dp[i - j] + mod) % mod;
    }
  }
  cout << dp[n] << '\n';
  return 0;
}