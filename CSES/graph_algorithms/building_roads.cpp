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

vector<vector<int> > adj;
vector<bool> used;

int bfs(int u) {
  queue<int> Q;
  used[u] = true;
  Q.push(u);
  int last_visited = u;
  while (!Q.empty()) {
    int par = Q.front();
    Q.pop();
    last_visited = par;
    for (int v : adj[par]) {
      if (!used[v]) {
        Q.push(v);
        used[v] = true;
      }
    }
  }
  return last_visited;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  adj.resize(n);
  used.resize(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    --u; --v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  vector<pair<int, int> > _tc;
  int last_get = -1;
  for (int i = 0; i < n; i++) {
    if (!used[i]) {
      if (i > 0) {
        _tc.emplace_back(last_get, i);
      }
      last_get = bfs(i);
    }
  }
  cout << (int)_tc.size() << '\n';
  for (int i = 0; i < (int)_tc.size(); i++) {
    cout << _tc[i].first + 1 << " " << _tc[i].second + 1 << '\n';
  }
  return 0;
}