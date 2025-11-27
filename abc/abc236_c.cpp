//queueに各駅と急行の駅を入れておき、queueの先頭で比べる。一致したらどっちも取り出し、各駅だけだったら各駅だけを取り出す。

#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  
  queue<string> station;
  queue<string> express;
  
  for (int i = 0; i < N; i++) {
    string s;
    cin >> s;
    station.push(s);
  }
  
  for (int i = 0; i < M; i++) {
    string s;
    cin >> s;
    express.push(s);
  }
  
  for (int i = 0; i < N; i++) {
    if (station.front() == express.front()) {
      cout << "Yes" << endl;
      station.pop();
      express.pop();
    } else {
      cout << "No" << endl;
      station.pop();
    }
  }
}