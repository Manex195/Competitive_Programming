#include <bits/stdc++.h>
using namespace std;

using int64 = long long;
template<typename T>
bool ckmin(T& a, T b) { return b < a ? a = b, 1 : 0; }
template<typename T>
bool ckmax(T& a, T b) { return b > a ? a = b, 1 : 0; }

int nt, np;
string t, p;
vector<int> where;

bool ok(int x) {
  int canget = 0;
  for (int i = 0; i < nt; i++) {
    if (where[i] >= x && t[i] == p[canget] && canget < np) ++canget;
  }
  return canget == np;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> t >> p;
  nt = (int)t.size();
  np = (int)p.size();
  where.resize(nt);
  for (int i = 0; i < nt; i++) {
    int per; cin >> per;
    --per;
    where[per] = i;
  }
  int l = 0, r = nt;
  while (l + 1 < r) {
    int m = l + (r - l) / 2;
    if (ok(m)) l = m;
    else r = m; 
  }
  cout << l << '\n';
  return 0;
}