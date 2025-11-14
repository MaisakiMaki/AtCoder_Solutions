// 基本は同じ位置で二つの文字列確認、breakされてなかったら一番後ろに挿入されてる。

#include <bits/stdc++.h>
using namespace std;

int main() {

  string S, T;

  cin >> S >> T;
  
  bool bre = false;
  
  for (int i = 0; i < S.size(); i++) {
    if (S.at(i) != T.at(i)) {
      cout << i + 1 << endl;
      bre = true;
      break;
    }
  }
  if (!bre) {
    cout << S.size() + 1 << endl;
  }
}