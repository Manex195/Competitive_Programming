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


// #include <bits/stdc++.h>

// using namespace std;

// const int INF = (int)1e9;
// const int N = 400000;
// int tree[N], A[N];

// void build(int node, int b, int e) {
//   if (b == e) {
//     tree[node] = A[b];
//     return;
//   }
//   int mid = b + (e - b) / 2; 
//   build(2 * node, b, mid);
//   build(2 * node + 1, mid + 1, e);
//   tree[node] = min(tree[2 * node], tree[2 * node + 1]);
// }

// int query(int node, int b, int e, int l, int r) {
//   if (r < b || l > e) return INF;
//   if (l <= b && e <= r) return tree[node];
//   int mid = b + (e - b) / 2;
//   return min(query(2 * node, b, mid, l, r), query(2 * node + 1, mid + 1, e, l, r));
// }

// void update(int node, int i, int val, int l, int r) {
//   if (l == r) {
//     tree[node] = val;
//     return;
//   }
//   int m = l + (r - l) / 2;
//   if (i <= m) {
//     update(2 * node, i, val, l, m);
//   } else {
//     update(2 * node + 1, i, val, m + 1, r);
//   }
//   tree[node] = min(tree[2 * node], tree[2 * node + 1]);
// }

// int main() {
//   ios::sync_with_stdio(false);
//   cin.tie(nullptr);
//   int n, q;
//   cin >> n >> q;
//   for (int i = 1; i <= n; i++) {
//     cin >> A[i];
//   }
//   build(1, 1, n);
//   while(q--) {
//     int op;
//     cin >> op;
//     if (op == 1) {
//       int i, val;
//       cin >> i >> val;
//       update(1, i + 1, val, 1, n);
//     } else { 
//       int l, r;
//       cin >> l >> r;
//       cout << query(1, 1, n, l + 1, r) << '\n';
//     }
//   }
//   return 0;
// }