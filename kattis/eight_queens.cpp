#include <bits/stdc++.h>
using namespace std;

using int64 = long long;
template<typename T>
bool ckmin(T& a, T b) { return b < a ? a = b, 1 : 0; }
template<typename T>
bool ckmax(T& a, T b) { return b > a ? a = b, 1 : 0; }
const int D = 8;
char board[D + 1][D + 1];

bool cant_place(int row, int col) {
  // upper left diagonal
  for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j) {
    if (board[i][j] == '*') return true;
  }
  // upper right diagonal
  for (int i = row - 1, j = col + 1; i >= 0 && j < D; --i, ++j) {
    if (board[i][j] == '*') return true;
  }
  return false;
}

bool possible() {
  vector<int> rows(D, 0), cols(D, 0);
  for (int i = 0; i < D; i++) {
    for (int j = 0; j < D; j++) {
      if (board[i][j] == '*') rows[i]++, cols[j]++;
    }
  }
  // should cover same rows.
  for (const int& r : rows) if (r > 1) return false;
  // should cover same columns.
  for (const int& c : cols) if (c > 1) return false;
  // check for diagonals.
  int queens = 0;
  for (int i = 0; i < D; i++) {
    for (int j = 0; j < D; j++) {
      if (board[i][j] == '*') {
        queens++;
        if (cant_place(i, j)) return false;
      }
    }
  }
  return true && queens == 8;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  for (int i = 0; i < D; i++) {
    for (int j = 0; j < D; j++) {
      cin >> board[i][j]; 
    }
  }
  cout << (possible() ? "valid" : "invalid") << '\n';
  return 0;
}
