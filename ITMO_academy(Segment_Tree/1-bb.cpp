#include <bits/stdc++.h>

using namespace std;

const int INF = (int)1e9;
const int N = 400000;
int tree[N], A[N];

void build(int node, int b, int e) {
  if (b == e) {
    tree[node] = A[b];
    return;
  }
  int mid = b + (e - b) / 2; 
  build(2 * node, b, mid);
  build(2 * node + 1, mid + 1, e);
  tree[node] = min(tree[2 * node], tree[2 * node + 1]);
}

int query(int node, int b, int e, int l, int r) {
  if (r < b || l > e) return INF;
  if (l <= b && e <= r) return tree[node];
  int mid = b + (e - b) / 2;
  return min(query(2 * node, b, mid, l, r), query(2 * node + 1, mid + 1, e, l, r));
}

void update(int node, int i, int val, int l, int r) {
  if (l == r) {
    tree[node] = val;
    return;
  }
  int m = l + (r - l) / 2;
  if (i <= m) {
    update(2 * node, i, val, l, m);
  } else {
    update(2 * node + 1, i, val, m + 1, r);
  }
  tree[node] = min(tree[2 * node], tree[2 * node + 1]);
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
      cout << query(1, 1, n, l + 1, r) << '\n';
    }
  }
  return 0;
}