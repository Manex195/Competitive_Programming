#include <bits/stdc++.h>
using namespace std;

using int64 = long long;
template<typename T>
bool ckmin(T& a, T b) { return b < a ? a = b, 1 : 0; }
template<typename T>
bool ckmax(T& a, T b) { return b > a ? a = b, 1 : 0; }

int closestLeft(vector<int>& a, int x) {
  int n = (int)a.size();
  int l = -1, r = n;
  while (l + 1 < r) {
    int m = l + (r - l) / 2;
    if (a[m] <= x) l = m;
    else r = m;
  }
  return l;
}

int closestRight(vector<int>& a, int x) {
  int n = (int)a.size();
  int l = -1, r = n;
  while (l + 1 < r) {
    int m = l + (r - l) / 2;
    if (a[m] < x) l = m;
    else r = m;
  }
  return r;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  int k;
  cin >> k;
  while (k--) {
    int l, r;
    cin >> l >> r;
    int ans = closestLeft(a, r) - closestRight(a, l) + 1;
    cout << ans << ' ';
  }
  return 0;
}