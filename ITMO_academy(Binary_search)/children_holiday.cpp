#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
using int64 = long long;
template<typename T>
bool ckmin(T& a, T b) { return b < a ? a = b, 1 : 0; }
template<typename T>
bool ckmax(T& a, T b) { return b > a ? a = b, 1 : 0; }
int64 m, n;
vector<pair<int64, pair<int64, int64> > > t;

int64 inflated(pair<int64, pair<int64, int64> > x, int64 trg) {
  int64 result = 0;
  result += x.s.f * (trg / (x.f * x.s.f + x.s.s));
  int64 rem = trg % (x.f * x.s.f + x.s.s);
  if (rem >= (x.f * x.s.f)) result += x.s.f;
  else result += (rem / x.f);
  return result;
}

bool ok(int64 trg) {
  int64 result = 0;
  for (int i = 0; i < n; i++) {
    result += 0LL + inflated(t[i], trg);
  }
  return result >= m;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> m >> n;
  t.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> t[i].f >> t[i].s.f >> t[i].s.s;
  }
  int64 low = -1, high = int64(2e9 + 5);
  while (low + 1 < high) {
    int64 mid = 0LL + low + (high - low) / 2;
    if (ok(mid)) high = mid;
    else low = mid;
  }
  cout << high << '\n';
  for (int i = 0; i < n; i++) {
    int64 curr = inflated(t[i], high);
    cout << min(m, curr) << " \n"[i == n - 1];
    m -= min(m, curr);
  }
  return 0;
}
