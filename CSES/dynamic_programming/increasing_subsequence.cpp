#include <bits/stdc++.h>
using namespace std;

using int64 = long long;
template<typename T>
bool ckmin(T& a, T b) { return b < a ? a = b, 1 : 0; }
template<typename T>
bool ckmax(T& a, T b) { return b > a ? a = b, 1 : 0; }

// for file input/output.
// void setIO(string fName) {
//   freopen((fName + ".in").c_str(), "r", stdin);
//   freopen((fName + ".out").c_str(), "w", stdout);
// }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> lis;
  for (int i = 0; i < n; i++) {
    auto it = lower_bound(lis.begin(), lis.end(), a[i]);
    if (it != lis.end()) {
      *it = a[i];
    } else {
      lis.push_back(a[i]);
    }
  }
  cout << (int)lis.size() << '\n';
  return 0;
}