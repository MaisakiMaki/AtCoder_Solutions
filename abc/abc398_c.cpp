// 被りがない人の最大値を出す。dataで人の数値とそのidxを記録、mapで被り確認。
// dataをsort,reverseをして降順に変え、mapから被ってない数字の中で一番数字が大きいものを記録
// そのあとdataからその数字を探索、発見したらその数字のsecond要素を出力

#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  map<long long, int> cnt;
  vector<pair<long long, int>> data;
  
  
  for (int i = 0; i < N; i++) {
    long long A;
    cin >> A;
    cnt[A]++;
    data.push_back(make_pair(A, i + 1));
  }
  
  sort(begin(data), end(data));
  reverse(begin(data), end(data));
  
  long long maxcnt = -1;
  
  bool is_ok = false;
  for (auto p : cnt) {
    if (p.second == 1) {
      //cout << "p.first: " << p.first << endl;
      if (maxcnt < p.first) {
        maxcnt = p.first;
        //cout << "max: " << maxcnt << endl;
        is_ok = true;
      }
    }
  }
  
  int ans = -1;
  
  if (is_ok) {
    for (int i = 0; i < N; i++) {
      if (maxcnt == data.at(i).first) {
        ans = data.at(i).second;
        break;
      }
    }
  }
  
  cout << ans << endl;
}