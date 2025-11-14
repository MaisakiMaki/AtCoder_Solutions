// mapで重複を見る。pairでも良かっただろうが、setを先に思いついちゃったのでそっからmapを使った。
// keyを教えてない状態でもm[key]++;で増やせちゃったのでそれは楽かなと
// for文も拡張forでpairとして出力されるからsecond要素を見て2で割ったものを足していけばペア数は追える。

#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  long long A;
  
  map<long long, int> m;
  
  int cnt = 0;
  
  for (int i = 0; i < N; i++) {
    cin >> A;
    m[A]++;
  }
  
  int ans = 0;
  
  for (auto p : m) {
    ans += p.second / 2;
  }
  
  cout << ans << endl;
}