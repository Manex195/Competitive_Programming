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
    int n, k; 
    cin >> n;
    if (n == 0) break;
    cin >> k;
    vector<int> wins(n, 0);
    vector<int> loses(n, 0);
    int totalGames = (k * n * (n - 1)) / 2;
    for (int i = 0; i < totalGames; i++) {
      int p1, p2;
      string m1, m2;
      cin >> p1 >> m1 >> p2 >> m2;
      --p1; --p2;
      if (m1 == "paper" && m2 == "rock") 
        wins[p1]++, loses[p2]++;
      else if (m1 == "rock" && m2 == "paper") 
        wins[p2]++, loses[p1]++;
      else if (m1 == "scissors" && m2 == "paper")
        wins[p1]++, loses[p2]++;
      else if (m1 == "paper" && m2 == "scissors")
        wins[p2]++, loses[p1]++;
      else if (m1 == "rock" && m2 == "scissors")
        wins[p1]++, loses[p2]++;
      else if (m1 == "scissors" && m2 == "rock")
        wins[p2]++, loses[p1]++;
    }
    for (int i = 0; i < n; i++) {
      double w = (double)wins[i];
      double l = (double)loses[i];
      if (wins[i] == 0 && loses[i] == 0) {
        cout << "-\n";
      } else {
        double winAverage = w / (w + l);
        cout << fixed << setprecision(3) << winAverage << '\n';
      }
    }
    cout << '\n';
  }
  return 0;
}







