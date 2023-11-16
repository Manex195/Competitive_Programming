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
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<string> numbers(n);
    for (int i = 0; i < n; i++) {
      cin >> numbers[i];
    }
    bool found = false;
    map<string, int> mp;
    sort(begin(numbers), end(numbers));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < (int)numbers[i].size(); j++) {
        string curr = "";
        for (int k = 0; k <= j; k++) {
          curr.push_back(numbers[i][k]);
        }
        if (mp[curr] > 0) {
          found = true;
          break;
        }
      }
      if (found) break;
      mp[numbers[i]]++;
    }
    cout << (found ? "NO" : "YES") << '\n'; 
  }
  return 0;
}