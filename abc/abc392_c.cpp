// pair型の配列を用意してidx、ゼッケン、見てる人の3要素を保存して、それをうまく使えばいける。

#include <bits/stdc++.h>
using namespace std;

int main() {
  int N; cin >> N;
  vector<pair<int, int>> data(N + 1);
  
  for (int i = 1; i <= N; i++) {
    int n; cin >> n;
    data.at(i) = make_pair(n, 0);
  }
  
  for (int i = 1; i <= N; i++) {
    int n; cin >> n;
    data.at(i).second = n;
  }
  
  vector<int> ans(N + 1);
  
  for (int i = 1; i <= N; i++) {
    int zek = data.at(i).second;
    int see = data.at(i).first;
    ans.at(zek) = data.at(see).second;
  }
  for (int i = 1; i <= N; i++) {
    cout << ans.at(i);
    if (i != N) {
      cout << " ";
    } else {
      cout << endl;
    }
  }
}