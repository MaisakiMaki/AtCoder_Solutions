// Nが10^5なので線形探索が可能。前からpre,curを比べて、相違があったらcntをインクリメントする。

#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  string S;
  cin >> N >> S;
  
  char previous = S.at(0);
  int cnt = 1;
  
  for (int i = 1; i < N; i++) {
    char current = S.at(i);
    if (previous != current) {
      cnt++;
    }
    previous = current;
  }
  
  cout << cnt << endl;
}