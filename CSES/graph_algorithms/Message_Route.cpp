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
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    --u; --v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<bool> used(n, false);
  vector<int> par(n, -1);
  vector<int> dist(n, 1);
  queue<int> Q;
  Q.push(0);
  while (!Q.empty()) {
    int u = Q.front();
    if (u == n - 1) break;
    Q.pop();
    for (int v : adj[u]) {
      if (!used[v]) {
        Q.push(v);
        par[v] = u;
        dist[v] += dist[u];
        used[v] = true;
      }
    }
  }
  if (!used[n - 1]) {
    cout << "IMPOSSIBLE\n";
  } else {
    cout << dist[n - 1] << '\n';
    vector<int> path;
    path.push_back(n - 1);
    int curr = n - 1;
    while (par[curr] != 0) {
      path.push_back(par[curr]);
      curr = par[curr];
    }
    path.push_back(0);
    reverse(path.begin(), path.end());
    for (int i = 0; i < (int)path.size(); i++) {
      cout << path[i] + 1 << " \n"[i == (int)path.size() - 1];
    }
  }
  return 0;
}
