#include <bits/stdc++.h>
using namespace std;

using int64 = long long;
using db64 = long double;
template<typename T>
bool ckmin(T& a, T b) { return b < a ? a = b, 1 : 0; }
template<typename T>
bool ckmax(T& a, T b) { return b > a ? a = b, 1 : 0; }

db64 c;
bool ok(db64 x) {
  return x * x + sqrt(x) + db64(0.0) >= c;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> c;
  db64 l = 0.0;
  db64 r = db64(1e10);
  for (int i = 0; i < 100; i++) {
    db64 m = l + (r - l) / 2;
    if (ok(m)) r = m;
    else l = m;
  }
  cout << setprecision(20);
  cout << r << '\n';
  return 0;
}