#include <bits/stdc++.h>
using namespace std;

using int64 = long long;
template<typename T>
bool ckmin(T& a, T b) { return b < a ? a = b, 1 : 0; }
template<typename T>
bool ckmax(T& a, T b) { return b > a ? a = b, 1 : 0; }

int n, k;
vector<int> cords;

bool ok(int x) {
  int placed = 1;
  int last_placed = cords[0];
  for (int i = 1; i < n; i++) {
    if (cords[i] - last_placed >= x) {
      placed++;
      last_placed = cords[i];
    }
  }
  return placed >= k;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> k;
  cords.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> cords[i];
  }
  int l = 0, r = 1e9;
  while (l + 1 < r) {
    int m = l + (r - l) / 2;
    if (ok(m)) l = m;
    else r = m;
  }
  cout << l << '\n';
  return 0;
}