#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../debugger/debug.h"
#else
#define debug(...) 420
#endif
using int64 = long long;
const int INF = (int)1e9 + 7;

// for file input/output.
// void setIO(string fName) {
//   freopen((fName + ".in").c_str(), "r", stdin);
//   freopen((fName + ".out").c_str(), "w", stdout);
// }
struct SegmentTree {
  SegmentTree *left, *right;
  int from, to, value;
  SegmentTree(int from, int to) : from(from), to(to), left(NULL), right(NULL), value(INF) {}
};

SegmentTree* build(const vector<int>& arr, int l, int r) {
  if (l > r) return NULL;
  SegmentTree* res = new SegmentTree(l, r);
  if (l == r) {
    res->value = min(res->value, arr[l]);
  } else {
    int m = l + (r - l) / 2;
    res->left = build(arr, l, m);
    res->right  = build(arr, m + 1, r);
    if (res->left != NULL) res->value = min(res->value, res->left->value);
    if (res->right != NULL) res->value = min(res->value, res->right->value);
  }
  return res;
}

int64 query(SegmentTree* tree, int l, int r) {
  if (tree == NULL) return 0;
  if (l <= tree->from && tree->to <= r) return tree->value;
  if (tree->to < l) return INF;
  if (r < tree->from) return INF;
  return min(query(tree->left, l, r), query(tree->right, l, r));
}

int64 update(SegmentTree* tree, int i, int val) {
  if (tree == NULL) return 0;
  if (tree->to < i) return tree->value;
  if (i < tree->from) return tree->value;
  if (tree->from == tree->to && tree->from == i) {
    tree->value = val;
  } else {
    tree->value = min(update(tree->left, i, val), update(tree->right, i, val));
  }
  return tree->value;
}


int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  SegmentTree* STree = build(a, 0, n - 1);
  while (q--) {
    int c;
    cin >> c;
    if (c == 1) {
      int i, val;
      cin >> i >> val;
      --i;
      update(STree, i, val);
    } else {
      int l, r;
      cin >> l >> r;
      --l; --r;
      cout << query(STree, l, r) << '\n';
    }
  }
  return 0;
}