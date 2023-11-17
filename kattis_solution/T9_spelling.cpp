#include <bits/stdc++.h>
using namespace std;

using int64 = long long;
template<typename T>
bool ckmin(T& a, T b) { return b < a ? a = b, 1 : 0; }
template<typename T>
bool ckmax(T& a, T b) { return b > a ? a = b, 1 : 0; }

class T9_Spelling {
private:
  map<string, int> keymap;
public:
  void test_case() {
    keymap["abc"] = 2; keymap["def"] = 3;
    keymap["ghi"] = 4; keymap["jkl"] = 5;
    keymap["mno"] = 6; keymap["pqrs"] = 7;
    keymap["tuv"] = 8; keymap["wxyz"] = 9;
    keymap[" "] = 0;
    string line;
    getline(cin, line);
    int prev;
    for (int i = 0; i < (int)line.size(); i++) {
      for (auto key : keymap) {
        string currkey = key.first;
        for (int k = 0; k < (int)currkey.size(); k++) {
          if (line[i] == currkey[k]) {
            if (prev == key.second) cout << " ";
            for (int rep = 0; rep <= k; rep++) 
              cout << key.second;
            prev = key.second;
          }
        }
      }
    }
    cout << '\n';
  }
  
  void solve() {
    int tt;
    cin >> tt;
    cin.ignore();
    for (int t = 1; t <= tt; t++) {
      cout << "Case #" << t << ": "; test_case();
    }
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  T9_Spelling solver;
  solver.solve();
  return 0;
}