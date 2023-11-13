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

    vector<int> jack(n);
    vector<int> jill(m);

    for (int i = 0; i < n; i++) cin >> jack[i];
    for (int i = 0; i < m; i++) cin >> jill[i];

    int l = 0, r = 0;
    int similar = 0;
    while (l < n && r < m) {
      if (jack[l] > jill[r]) r++;
      else if (jack[l] < jill[r]) l++;
      else similar++, l++, r++;
    }
    cout << similar << '\n';
  }
  return 0;
}