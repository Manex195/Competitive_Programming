#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../debugger/debug.h"
#else
#define debug(...) 420
#endif
using int64 = long long;

struct SegmentTree {
  SegmentTree *left, *right;
  int from, to;
  int64 value;
  SegmentTree(int from, int to) : from(from), to(to), left(NULL), right(NULL), value(0LL) {}
};

SegmentTree* build(const vector<int>& arr, int l, int r) {
  if (l > r) return NULL;
  SegmentTree* res = new SegmentTree(l, r);
  if (l == r) {
    res->value = 0LL + arr[l];
  } else {
    int m = l + (r - l) / 2;
    res->left = build(arr, l, m);
    res->right  = build(arr, m + 1, r);
    if (res->left != NULL) res->value += 0LL + res->left->value;
    if (res->right != NULL) res->value += 0LL + res->right->value;
  }
  return res;
}

int64 query(SegmentTree* tree, int l, int r) {
  if (tree == NULL) return 0;
  if (l <= tree->from && tree->to <= r) return tree->value;
  if (tree->to < l) return 0;
  if (r < tree->from) return 0;
  return query(tree->left, l, r) + query(tree->right, l, r);
}

int64 update(SegmentTree* tree, int i, int val) {
  if (tree == NULL) return 0;
  if (tree->to < i) return tree->value;
  if (i < tree->from) return tree->value;
  if (tree->from == tree->to && tree->from == i) {
    tree->value = val;
  } else {
    tree->value = update(tree->left, i, val) + update(tree->right, i, val);
  }
  return tree->value;
}
// for file input/output.
// void setIO(string fName) {
//   freopen((fName + ".in").c_str(), "r", stdin);
//   freopen((fName + ".out").c_str(), "w", stdout);
// }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (int& num : a) {
    cin >> num;
  }
  SegmentTree* stree = build(a, 0, n - 1);
  while (q--) {
    int c;
    cin >> c;
    if (c == 2) {
      int l, r;
      cin >> l >> r;
      --l; --r;
      cout << query(stree, l, r) << '\n';
    } else {
      int i, val;
      cin >> i >> val;
      --i;
      update(stree, i, val);
    }
  }
  return 0;
}