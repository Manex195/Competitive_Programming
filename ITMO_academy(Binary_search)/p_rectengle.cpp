#include <bits/stdc++.h>
using namespace std;

using int64 = long long;
template<typename T>
bool ckmin(T& a, T b) { return b < a ? a = b, 1 : 0; }
template<typename T>
bool ckmax(T& a, T b) { return b > a ? a = b, 1 : 0; }
int64 w, h, n;

bool ok(int64 x) {
  return 1LL * (x / w) * (x / h) >= n;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> w >> h >> n;
  // l is 0 if we cannot fit any.
  int64 l = 0, r = 1;
  // finding smallest r that is good.
  while (!ok(r)) r <<= 1;
  while (l + 1 < r) {
    int64 m = l + (r - l) / 2;
    if (ok(m)) r = m;
    else l = m;
  }
  cout << r << '\n';
  return 0;
}