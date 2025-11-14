// 前から見ていけばいい。Nが10^100000とかいうキチガイ数字なのでlong longでも入らない。文字列を使う。
// 前から文字列操作、0だったらカウンタを進めてその次も0だったらカウンタを進めずiを一個進める。

#include <bits/stdc++.h>
using namespace std;

int main() {
  string N;
  cin >> N;
  
  int nlen = N.size();
  
  int cnt = 0;
  
  for (int i = 0; i < nlen; i++) {
    if (N.at(i) == '0') {
      cnt++;
      if (i < nlen - 1 && N.at(i + 1) == '0') {
        i++;
      }
    } else {
      cnt++;
    }
  }
  
  cout << cnt << endl;
}