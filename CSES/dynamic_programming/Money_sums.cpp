#include <bits/stdc++.h>
using namespace std;

using int64 = long long;
template<typename T>
bool ckmin(T& a, T b) { return b < a ? a = b, 1 : 0; }
template<typename T>
bool ckmax(T& a, T b) { return b > a ? a = b, 1 : 0; }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  int maxn = n * 1000;
  vector<vector<bool>> dp(n + 1, vector<bool>(maxn, false));

  for (int i = 0; i <= n; i++) dp[i][0] = true;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= maxn; j++) {
      if (a[i - 1] <= j) {
        dp[i][j] = (dp[i - 1][j - a[i - 1]] || (dp[i - 1][j]));
      } else {
        dp[i][j] = dp[i - 1][j];
      }
    } 
  }
  vector<int> possible_sums;
  for (int i = 1; i <= maxn; i++) {
    if (dp[n][i]) {
      possible_sums.push_back(i);
    }
  }
  int total = (int)possible_sums.size();
  cout << total << '\n';
  for (int i = 0; i < total; i++) {
    cout << possible_sums[i] << " \n"[i == total - 1];
  }
  return 0;
}