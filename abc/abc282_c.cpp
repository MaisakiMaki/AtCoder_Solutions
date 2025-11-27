// boolを"をトリガーとしてtrueとfalseを動かすだけ、なんでこれが405より難易度が上なのか本当にわからない。

#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  string s;
  
  cin >> N >> s;
  
  bool is_cover = false;
  
  for (int i = 0; i < N; i++) {
    if (s.at(i) == ',' && !is_cover) {
      s.at(i) = '.';
    }
    if (s.at(i) == '"') {
      is_cover = !is_cover;
    }
  }
  cout << s << endl;
}