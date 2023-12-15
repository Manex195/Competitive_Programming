#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "../debugger/debug.h"
#else
#define debug(...) 420
#endif
using int64 = long long;
const int INF = (int)1e9;

struct Item {
  int num, freq;
};

struct segTree {
  vector<Item> mins;
  int len;

  void init(int n) {
    len = 1;
    while (len < n) len *= 2;
    mins.assign(2 * len, {INF, 0});
  }

  Item combine(Item a, Item b) {
    if (a.num < b.num) return a;
    if (b.num < a.num) return b;
    return {a.num, a.freq + b.freq};
  }

  // root = r.
  void build(vector<int>& a, int r, int lx, int rx) {
    if (rx - lx == 1) {
      if (lx < (int)a.size()) {
        mins[r] = {a[lx], 1};
      }
      return;
    }
    int m = lx + (rx - lx) / 2;
    build(a, 2 * r + 1, lx, m);
    build(a, 2 * r + 2, m, rx);
    mins[r] = combine(mins[2 * r + 1], mins[2 * r + 2]);
  }
  void build(vector<int>& a) {
    build(a, 0, 0, len);
  }
  // here root p.
  Item get_mins(int l, int r, int p, int lx, int rx) {
    if (lx >= r || rx <= l) return {INF, 0};
    if (lx >= l && rx <= r) return mins[p];
    int m = lx + (rx - lx) / 2;
    auto lmin = get_mins(l, r, 2 * p + 1, lx, m);
    auto rmin = get_mins(l, r, 2 * p + 2, m, rx);
    return combine(lmin, rmin);
  }

  // query from segment sum (l to r - 1).
  Item query(int l, int r) {
    return get_mins(l, r, 0, 0, len);
  }
  // here root r.
  void update(int i, int x, int r, int lx, int rx) {
    if (rx - lx == 1) { mins[r] = {x, 1}; return; }
    int m = lx + (rx - lx) / 2;
    if (i < m) update(i, x, 2 * r + 1, lx, m);
    else  update(i, x, 2 * r + 2, m, rx);
    mins[r] = combine(mins[2 * r + 1], mins[2 * r + 2]);
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
  while(q--) {
    int op;
    cin >> op;
    if (op == 1) {
      int i, val;
      cin >> i >> val;
      st.update(i, val);
    } else { 
      int l, r;
      cin >> l >> r;
      auto ans = st.query(l, r);
      cout << ans.num << ' ' << ans.freq << '\n';
    }
  }
  return 0;
}