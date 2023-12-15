#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../debugger/debug.h"
#else
#define debug(...) 420
#endif
using int64 = long long;
const int INF= (int)1e9 + 7;
// for file input/output.
// void setIO(string fName) {
//   freopen((fName + ".in").c_str(), "r", stdin);
//   freopen((fName + ".out").c_str(), "w", stdout);
// }

struct segTree {
  vector<int> mins;
  int len;

  void init(int n) {
    len = 1;
    while (len < n) len *= 2;
    mins.assign(2 * len, INF);
  }
  // root = r.
  void build(vector<int>& a, int r, int lx, int rx) {
    if (rx - lx == 1) {
      if (lx < (int)a.size()) {
        mins[r] = min(mins[r], a[lx]);
      }
      return;
    }
    int m = lx + (rx - lx) / 2;
    build(a, 2 * r + 1, lx, m);
    build(a, 2 * r + 2, m, rx);
    mins[r] = min(mins[2 * r + 1], mins[2 * r + 2]);
  }
  void build(vector<int>& a) {
    build(a, 0, 0, len);
  }
  // here root p.
  int get_mins(int l, int r, int p, int lx, int rx) {
    if (lx >= r || rx <= l) return INF;
    if (lx >= l && rx <= r) return mins[p];
    int m = lx + (rx - lx) / 2;
    int lmin = get_mins(l, r, 2 * p + 1, lx, m);
    int rmin = get_mins(l, r, 2 * p + 2, m, rx);
    return min(lmin, rmin);
  }

  // query from segment sum (l to r - 1).
  int query(int l, int r) {
    return get_mins(l, r, 0, 0, len);
  }
  // here root r.
  void update(int i, int x, int r, int lx, int rx) {
    if (rx - lx == 1) { mins[r] = x; return; }
    int m = lx + (rx - lx) / 2;
    if (i < m) update(i, x, 2 * r + 1, lx, m);
    else  update(i, x, 2 * r + 2, m, rx);
    mins[r] = min(mins[2 * r + 1], mins[2 * r + 2]);
  }

  void update(int i, int x) {
    update(i, x, 0, 0, len);
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
      st.update(i, x);
    } else {
      int l, r;
      cin >> l >> r;
      cout << st.query(l, r) << '\n';
    }
  }
  return 0;
}