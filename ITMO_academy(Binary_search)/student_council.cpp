#include <bits/stdc++.h>
using namespace std;

using int64 = long long;
template<typename T>
bool ckmin(T& a, T b) { return b < a ? a = b, 1 : 0; }
template<typename T>
bool ckmax(T& a, T b) { return b > a ? a = b, 1 : 0; }

int k, n;
vector<int64> a;

bool ok(int64 x) {
  // number of groups assuming can be formed.
  int64 group = x;
  // required members for x group.
  int64 reqMem = x * k * 1LL;
  for (int i = 0; i < n; i++) {
    // will take students for a group 1 each for the group or
    // if we have less then will take it for few groups.
    reqMem -= min(a[i], group);
  }
  return reqMem <= 0;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> k >> n;
  a.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int64 l = 0, r = int64(5 * 1e10 + 10);
  while (l + 1 < r) {
    int64 m = l + (r - l) / 2;
    if (ok(m)) l = m;
    else r = m;
  }
  cout << l << '\n';
  return 0;
}