#include <bits/stdc++.h>
using namespace std;

using int64 = long long;
template<typename T>
bool ckmin(T& a, T b) { return b < a ? a = b, 1 : 0; }
template<typename T>
bool ckmax(T& a, T b) { return b > a ? a = b, 1 : 0; }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  while (true) {
    int n, m;
    cin >> n >> m;
    if (n == 0 && m == 0) break;
    unordered_map<int, int> jack;
    unordered_map<int, int> jill;
    for (int i = 0; i < n; i++) {
      int x; cin >> x;
      jack[x]++;
    }
    int ans = 0;
    for (int i = 0; i < m; i++) {
      int x; cin >> x;
      if (jack[x] > 0 && jill[x] == 0) ans++;
      jill[x]++; 
    }
    cout << ans << '\n';
  }
  return 0;
}