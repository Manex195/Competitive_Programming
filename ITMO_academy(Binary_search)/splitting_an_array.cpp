#include <bits/stdc++.h>
using namespace std;

using int64 = long long;
template<typename T>
bool ckmin(T& a, T b) { return b < a ? a = b, 1 : 0; }
template<typename T>
bool ckmax(T& a, T b) { return b > a ? a = b, 1 : 0; }

int n, k;
vector<int64> a;

bool ok(int64 x) {
  int64 sum = 0;
  int64 segs = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] > x) return false;
    if (0LL + sum + a[i] < x) {
      sum += 0LL + a[i];
    } else if (0LL + sum + a[i] == x) {
      segs++;
      sum = 0;
    }  else {
      sum = a[i];
      segs++;
    }
    if (i == n - 1 && sum > 0) segs++;
  }
  return segs <= k;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> k;
  a.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int64 l = 0, r = 1LL * n * 1e9;
  while (l + 1 < r) {
    int64 m = 0LL + l + (r - l) / 2;
    if (ok(m)) r = m;
    else l = m;
  }
  cout << r << '\n';
  return 0;
}