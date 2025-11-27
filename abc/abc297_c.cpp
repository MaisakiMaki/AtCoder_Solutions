// 二次元配列なんて用意する必要はない。Hのループで文字列を読み込み、その中のWのループでTが連続しているかを見るだけ。
// 100*100しかない。雑魚

#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  
  cin >> H >> W;
  
  for (int i = 0; i < H; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < W; j++) {
      if (s.at(j) == 'T') {
        if (j < W - 1 && s.at(j + 1) == 'T') {
          s.at(j) = 'P';
          s.at(j + 1) = 'C';
          j++;
        }
      }
     
    }
     cout << s << endl;
  }
}