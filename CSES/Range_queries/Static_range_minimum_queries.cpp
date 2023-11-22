#include<bits/stdc++.h>
using namespace std;

const int INF = (int)1e9;
const int maxn = 200000;
const int rootn = 450;
int A[maxn + 5];
int Block[rootn];

int main() {
  int N, Q;
  cin >> N >> Q;  
  for(int i = 0; i < N; i++) cin >> A[i];
  int B = ceil(sqrt(N));
  int M = sqrt(N);
  int l = 0, r = 0;
  int curr = 0;
  while (l < N && r < N) {
    int curr_min = INF;
    while (r < l + M) {
      curr_min = min(curr_min, A[r]);
      r++;
    }
    Block[curr] = curr_min;
    curr++;
    if (curr == B - 1) break;
    l = r;
  }
  Block[curr] = INF;
  for (int i = r; i < N; i++) Block[curr] = min(Block[curr], A[i]);

  while (Q--) {
    int L, R;
    cin >> L >> R;
    --L; --R;
    int ans = INF;
    int BL = min(B - 1, L / M);
    int BR = min(B - 1, R / M);
    for (int i = BL + 1; i <= BR - 1; i++) ans = min(ans, Block[i]);
    int pl = max(L, min(M * (BL + 1), R));
    int pr = max(L, M * BR);
    for (int i = L; i < pl; i++) ans = min(ans, A[i]);
    for (int i = pr; i <= R; i++) ans = min(ans, A[i]);
    cout << ans << '\n';
  }
  return 0;
}