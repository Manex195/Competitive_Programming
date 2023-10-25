#include <bits/stdc++.h>
using namespace std;

using int64 = long long;
using db64 = long double;
template<typename T>
bool ckmin(T& a, T b) { return b < a ? a = b, 1 : 0; }
template<typename T>
bool ckmax(T& a, T b) { return b > a ? a = b, 1 : 0; }

const db64 INF = 2e18;
int n;
vector<pair<db64, db64>> xv;

bool ok(db64 x) {
  db64 lb = -INF, rb = INF;
  for (int i = 0; i < n; i++) {
    lb = max(lb, xv[i].first - x * xv[i].second);
    rb = min(rb, xv[i].first + x * xv[i].second);
  }
  return (rb - lb) > 0;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  xv.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> xv[i].first >> xv[i].second;
  }
  db64 l = 0;
  db64 r = 1e18;
  for (int i = 0; i < 100; i++) {
    db64 m = l + (r - l) / 2;
    if (ok(m)) r = m;
    else l = m;
  }
  cout << fixed << setprecision(7);
  cout << r << '\n';
  return 0;
}