#include <bits/stdc++.h>
using namespace std;

using int64 = long long;
template<typename T>
bool ckmin(T& a, T b) { return b < a ? a = b, 1 : 0; }
template<typename T>
bool ckmax(T& a, T b) { return b > a ? a = b, 1 : 0; }

int64 nb, ns, nc;
int64 pb, ps, pc;
int64 r;
int b = 0, c = 0, s = 0;

bool ok(int64 x) {
  int64 total = 0;
  total += max(0LL, (x * b - nb) * pb) ;
  total += max(0LL, (x * s - ns) * ps);
  total += max(0LL, (x * c - nc) * pc);
  return total <= r;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string resp;
  cin >> resp;
  cin >> nb >> ns >> nc >> pb >> ps >> pc >> r;
  for (int i = 0; i < (int)resp.size(); i++) {
    if (resp[i] == 'B') b++;
    else if (resp[i] == 'C') c++;
    else s++;
  } 
  int64 l = 0;
  int64 h = int64(1e15 + 5);
  while (l + 1 < h) {
    int64 m = 0LL + l + (h - l) / 2;
    if (ok(m)) l = m;
    else h = m;
  }
  cout << l << '\n';
  return 0;
}