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
  int n;
  while (cin >> n) {
    bool is_st = true, is_pq = true, is_q = true;
    stack<int> st;
    queue<int> q;
    priority_queue<int> pq;
    for (int i = 0; i < n; i++) {
      int cmd, x;
      cin >> cmd >> x;
      if (cmd == 1) {
        if (is_q) q.push(x);
        if (is_st) st.push(x);
        if (is_pq) pq.push(x);
      } else {
        if (q.empty() || q.front() != x) is_q = false;
        else q.pop();
        if (pq.empty() || pq.top() != x) is_pq = false;
        else pq.pop();
        if (st.empty() || st.top() != x) is_st = false;
        else st.pop();
      }
    }
    if (is_pq && !is_q && !is_st) {
      cout << "priority queue\n";
    } else if (!is_pq && is_q && !is_st) {
      cout << "queue\n";
    } else if (!is_pq && !is_q && is_st) {  
      cout << "stack\n";
    } else if (!is_pq && !is_st && !is_pq) {
      cout << "impossible\n";
    } else {
      cout << "not sure\n";
    }
  }
  return 0;
}