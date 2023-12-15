#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../debugger/debug.h"
#else
#define debug(...) 420
#endif
using int64 = long long;
const int INF = (int)1e9;

const int N = 100100;
int A[N];
pair<int, int> tree[4 * N];

pair<int, int> combine(pair<int, int> a, pair<int, int> b) {
  if (a.first < b.first) return a;
  if (b.first < a.first) return b;
  return {a.first, a.second + b.second};
}

void build(int node, int lx, int rx) {
  if (lx == rx) {
    tree[node] = {A[lx], 1};;
    return;
  }
  int mid = lx + (rx - lx) / 2; 
  build(2 * node, lx, mid);
  build(2 * node + 1, mid + 1, rx);
  tree[node] = combine(tree[2 * node], tree[2 * node + 1]);
}

pair<int, int> query(int node, int lx, int rx, int l, int r) {
  if (r < lx || l > rx) return {INF, 0};
  if (l <= lx && rx <= r) return tree[node];
  int mid = lx + (rx - lx) / 2;
  return combine(query(2 * node, lx, mid, l, r), query(2 * node + 1, mid + 1, rx, l, r));
}

void update(int node, int i, int val, int l, int r) {
  if (l == r) {
    tree[node] = {val, 1};
    return;
  }
  int m = l + (r - l) / 2;
  if (i <= m) {
    update(2 * node, i, val, l, m);
  } else {
    update(2 * node + 1, i, val, m + 1, r);
  }
  tree[node] = combine(tree[2 * node], tree[2 * node + 1]);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, q;
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> A[i];
  }
  build(1, 1, n);
  while(q--) {
    int op;
    cin >> op;
    if (op == 1) {
      int i, val;
      cin >> i >> val;
      update(1, i + 1, val, 1, n);
    } else { 
      int l, r;
      cin >> l >> r;
      auto ans = query(1, 1, n, l + 1, r);
      cout << ans.first << ' ' << ans.second << '\n';
    }
  }
  return 0;
}