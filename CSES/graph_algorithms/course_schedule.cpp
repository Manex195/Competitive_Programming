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
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    adj[u].push_back(v);
  }
  vector<bool> used(n, false);
  bool _possible = true;
  vector<int> par(n, -1);
  vector<int> order;
  function<void(int)> dfs = [&] (int v) {
    used[v] = true;
    for (auto u : adj[v]) {
      if (used[u] && par[v] == u) {
        _possible = false;
      }
      if (!used[u]) {
        par[u] = v;
        dfs(u);
      }
    }
    order.push_back(v);
  };

  for (int i = 0; i < n; i++) {
    if (!used[i]) dfs(i);
  }
  if (!_possible) {
    cout << "IMPOSSIBLE\n";
    return 0;
  }

  set<int> white;
  set<int> black;
  set<int> grey;
  bool _cyclic = false;
  for (int i = 0; i < n; i++) white.insert(i);

  function<void(int)> is_cyclic = [&] (int v) {
    white.erase(v);
    grey.insert(v);

    for (auto u : adj[v]) {
      if (white.find(u) != white.end()) {
        is_cyclic(u);
      }
      if (grey.find(u) != grey.end()) {
        _cyclic = true;
      }
    }
    black.insert(v);
    grey.erase(v);
  };


  for (int i = 0; i < n; i++) is_cyclic(i);

  if (!_cyclic) {
    reverse(order.begin(), order.end());
    for (int i = 0; i < n; i++) {
      cout << order[i] + 1 << " \n"[i == n - 1];
    }
  } else {
    cout << "IMPOSSIBLE";
  }
  return 0;
}