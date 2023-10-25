#include <bits/stdc++.h>
using namespace std;

using int64 = long long;
template<typename T>
bool ckmin(T& a, T b) { return b < a ? a = b, 1 : 0; }
template<typename T>
bool ckmax(T& a, T b) { return b > a ? a = b, 1 : 0; }

int n, x, y;

bool ok(int k) {
  return (k / x) + ((k - x) / y) >= n; 
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> x >> y;
  if (x > y) swap(x, y);
  int l = 0, r = 2e9;
  while (l + 1 < r) {
    int m = l + (r - l) / 2;
    if (ok(m)) r = m;
    else l = m;
  }
  cout << r << '\n';
  return 0;
}