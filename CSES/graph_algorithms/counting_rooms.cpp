#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../../debugger/debug.h"
#else
#define debug(...) 420
#endif
using int64 = long long;

// for file input/output.
// void setIO(string fName) {
//   freopen((fName + ".in").c_str(), "r", stdin);
//   freopen((fName + ".out").c_str(), "w", stdout);
// }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<vector<char>> building(n, vector<char>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> building[i][j];
    }
  }
  vector<vector<bool>> used(n, vector<bool>(m, false));
  function<void(int, int)> dfs = [&] (int i, int j) {
    if (i < 0 || j < 0 || i >= n || j >= m) return;
    if (used[i][j]) return;
    if (building[i][j] != '.') return;
    used[i][j] = true;
    dfs(i + 1, j);
    dfs(i - 1, j);
    dfs(i, j + 1);
    dfs(i, j - 1);
  };
  int total_rooms = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (building[i][j] == '.' && !used[i][j]) {
        total_rooms++;
        dfs(i, j);
      }
    }
  }
  cout << total_rooms << '\n';
  return 0;
}