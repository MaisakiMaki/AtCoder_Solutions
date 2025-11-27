// 全探索。文字列探索で7があるか探し、あったらcontinue、なかったら8進法にして文字列探索。
// Geminiの話ではhas7関数で行けるという。こんな簡単にいけたのか

#include <bits/stdc++.h>
using namespace std;

string ten2eight(int n) {
  string s;
  while(n > 0) {
    s  += to_string(n % 8);
    n /= 8;
  }
  reverse(s.begin(), s.end());
  return s;
}

"""
n進法の時に7を持っているかを調べるアルゴリズム
bool has7(int n, int base) {
    while(n > 0) {
        if (n % base == 7) return false;
        n /= base;
    }
    return true;
}
"""

int main() {
  int N; cin >> N;
  
  bool is_ok = true;
  
  int cnt = 0;
  
  for (int i = 1; i <= N; i++) {
    is_ok = true;
    string s = to_string(i);
    //cout << s << endl;
    for (int j = 0; j < s.size(); j++) {
      
      if (s.at(j) == '7') {
        is_ok = false;
        break;
      }
    }
    //cout << is_ok << endl;
    if (!is_ok) {
      continue;
    } else {
      string ans = ten2eight(i);
      for (int j = 0; j < ans.size(); j++) {
        if (ans.at(j) == '7') {
          is_ok = false;
          break;
        }
      }
    }
    if (is_ok) {
      cnt++;
    }
  }
  cout << cnt << endl;
}

