#include <bits/stdc++.h>
using namespace std;

using int64 = long long;
template<typename T>
bool ckmin(T& a, T b) { return b < a ? a = b, 1 : 0; }
template<typename T>
bool ckmax(T& a, T b) { return b > a ? a = b, 1 : 0; }

// always leave seat up. 
int policy1(const string& s) {
  char curr = s[0];
  int adjustments = 0;
  for (int i = 1; i < (int)s.size(); i++) {
    // we need to adjust 2 times in these case as we need to seat down
    // and then again we need to leave seat up.
    if (curr == 'U' && s[i] == 'D') {
      adjustments += 2;
    } else if (curr == 'D') adjustments++;
    // set the seat up.
    curr = 'U';
  }
  return adjustments;
}
// always leave seat down. 
int policy2(const string& s) {
  char curr = s[0];
  int adjustments = 0;
  for (int i = 1; i < (int)s.size(); i++) {
    // here it is the same case as in the policy one.
    if (curr == 'D' && s[i] == 'U') {
      adjustments += 2;
    } else if (curr == 'U') adjustments++;
    // always put seat down according to policy.
    curr = 'D';
  }
  return adjustments;
}
// always leave as it is.
int policy3(const string& s) {
  char curr = s[0];
  int adjustments = 0;
  for (int i = 1; i < (int)s.size(); i++) {
    // we will leave the seat as it is. So, if it is down
    // and preference is down then we need to adjust it so it is 
    // only one adjustment as we will leave as it is.
    if (curr != s[i]) {
      adjustments++;
    }
    // so now the seat will be as it is.
    curr = s[i];
  }
  return adjustments;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  cin >> s;
  cout << policy1(s) << '\n';
  cout << policy2(s) << '\n';
  cout << policy3(s) << '\n';
  return 0;
}