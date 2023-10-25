#include <bits/stdc++.h>
using namespace std;

using int64 = long long;
template<typename T>
bool ckmin(T& a, T b) { return b < a ? a = b, 1 : 0; }
template<typename T>
bool ckmax(T& a, T b) { return b > a ? a = b, 1 : 0; }
int n, k;
vector<int> a;

bool ok(double x) {
  int total = 0;
  for (int i = 0; i < n; i++) {
    total += (a[i] / x);
  }
  return total >= k;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> k;
  a.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  double l = 0, r = 1e8;
  for (int i = 0; i < 100; i++) {
    double m = l + (r - l) / 2;
    if (ok(m)) l = m;
    else r = m;
  }
  cout << setprecision(15);
  cout << l << '\n';
  return 0;
}