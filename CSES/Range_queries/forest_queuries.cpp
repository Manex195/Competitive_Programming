#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "../debugger/debug.h"
#else
#define debug(...) 420
#endif

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n, q;
  cin >> n >> q;
  vector<vector<int>> forest(n + 1, vector<int>(n + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      char x;
      cin >> x;
      forest[i][j] = (x == '*');
    }
  }
  vector<vector<int>> trees(n + 1, vector<int>(n + 1, 0));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      trees[i][j] = trees[i][j - 1] + trees[i - 1][j] + forest[i][j] - trees[i - 1][j - 1];
    }
  }
  while (q--) {
    int fx, fy, sx, sy;
    cin >> fx >> fy >> sx >> sy;
    cout << trees[sx][sy] - trees[sx][fy - 1] - trees[fx - 1][sy] + trees[fx - 1][fy - 1] << '\n';
  }
  return 0;
}