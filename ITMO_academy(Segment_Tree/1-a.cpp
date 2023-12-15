#include <bits/stdc++.h>
using namespace std;

#ifndef LOCAL
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

struct segTree {
  vector<int64> sums; 
  int len;

  void init(int n) {
    len = 1;
    while (len < n) len *= 2;
    sums.assign(2 * len, 0LL);
  }
  // root = r.
  void build(vector<int>& a, int r, int lx, int rx) {
    if (rx - lx == 1) {
      if (lx < (int)a.size())
        sums[r] = a[lx];
      return;
    }
    int m = lx + (rx - lx) / 2;
    build(a, 2 * r + 1, lx, m);
    build(a, 2 * r + 2, m, rx);
    sums[r] = sums[2 * r + 1] + sums[2 * r + 2];
  }
  void build(vector<int>& a) {
    build(a, 0, 0, len);
  }
  // here root p.
  int64 getsums(int l, int r, int p, int lx, int rx) {
    if (lx >= r || rx <= l) return 0;
    if (lx >= l && rx <= r) return sums[p];
    int m = lx + (rx - lx) / 2;
    int64 lsum = getsums(l, r, 2 * p + 1, lx, m);
    int64 rsum = getsums(l, r, 2 * p + 2, m, rx);
    return lsum + rsum;
  }
  // query from segment sum (l to r - 1).
  int64 query(int l, int r) {
    return getsums(l, r, 0, 0, len);
  }
  // here root r.
  void set(int i, int x, int r, int lx, int rx) {
    if (rx - lx == 1) {
      sums[r] = x;
      return; 
    }
    int m = lx + (rx - lx) / 2;
    if (i < m) set(i, x, 2 * r + 1, lx, m);
    else set(i, x, 2 * r + 2, m, rx);
    sums[r] = sums[2 * r + 1] + sums[2 * r + 2];
  }

  void set(int i, int x) {
    set(i, x, 0, 0, len);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  segTree st;
  st.init(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  st.build(a);
  while (q--) {
    int op;
    cin >> op;
    if (op == 1) {
      int i, x;
      cin >> i >> x;
      st.set(i, x);
    } else {
      int l, r;
      cin >> l >> r;
      cout << st.query(l, r) << '\n';
    }
  }
  return 0;
}