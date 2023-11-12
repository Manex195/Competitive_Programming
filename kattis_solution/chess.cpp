#include <bits/stdc++.h>
using namespace std;

using int64 = long long;
template<typename T>
bool ckmin(T& a, T b) { return b < a ? a = b, 1 : 0; }
template<typename T>
bool ckmax(T& a, T b) { return b > a ? a = b, 1 : 0; }

bool valid(int x, int y) {
  return (x <= 8 && x >=1 && y <= 8 && y >= 1);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    char C1, C2;
    int y1, y2;
    cin >> C1 >> y1 >> C2 >> y2;
    int x1 = (int)(C1 - 'A' + 1);
    int x2 = (int)(C2 - 'A' + 1);
    if (x1 == x2 && y1 == y2) {
      cout << "0 ";
      cout << C2 << " " << y2 << '\n';
      continue;
    }

    vector<pair<int, int>> p1;
    // possible movies from initial position.
    for (int i = 0; i < 8; i++) {
      if (valid(x1 + i, y1 + i))
        p1.emplace_back(x1 + i, y1 + i);
      if (valid(x1 - i, y1 + i)) 
        p1.emplace_back(x1 - i, y1 + i);
      if (valid(x1 + i, y1 - i))
        p1.emplace_back(x1 + i, y1 - i);
      if (valid(x1 - i, y1 - i)) 
        p1.emplace_back(x1 - i, y1 - i);
    }
    bool found = false;
    for (auto [x, y] : p1) {
      if (x == x2 && y == y2) {
        cout << 1 << " " << C1 << " " << y1 << " " << C2 << " " << y2 << '\n'; 
        found = true; 
      }
    }
    if (found) continue;
    vector<pair<int, int>> p2;
    // possible movies from desitination.
    // we might need two moves so we need intersection of the two positions.
    for (int i = 0; i < 8; i++) {
      if (valid(x2 + i, y2 + i))
        p2.emplace_back(x2 + i, y2 + i);
      if (valid(x2 - i, y2 + i)) 
        p2.emplace_back(x2 - i, y2 + i);
      if (valid(x2 + i, y2 - i))
        p2.emplace_back(x2 + i, y2 - i);
      if (valid(x2 - i, y2 - i)) 
        p2.emplace_back(x2 - i, y2 - i);
    }
    found = false;
    pair<int, int> insPoint;
    for (auto [ix1, iy1] : p1)  {
      for (auto [ix2, iy2] : p2) {
        if (ix1 == ix2 && iy1 == iy2) {
          insPoint = {ix1, iy1};
          found = true;
        }
      }
    }
    if (found) {
      cout << 2 << " " << C1 << " " << y1 <<  " ";
      cout << char(insPoint.first + 'A' - 1) << " " << insPoint.second;
      cout <<  " " << C2 << " " << y2 << '\n';
    } else {
      cout << "Impossible\n";
    }
  }
  return 0;
}