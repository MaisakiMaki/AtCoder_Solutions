// queueを上手く使う。queueが要素となるシリンダを記録する配列を用意し、各シリンダごとに特定の色のボールを入れ、そのシリンダの一番上の色の個数を二次元配列に入れる。
// 先ほど入れた二次元配列を前から操作し、特定の色の要素数が2だったらその二つでpairを作り、queueに入れる。
// その後、queueに入れたpairを元にシリンダのボールを取り出しカウンタを動かす。また、それごとに二次元配列に取り出した後に出てきた色を記録する
// 記録した色の要素数が2になったら逐一その要素のpairを作りqueueに突っ込む。
// 最終的にqueueの要素が無くなった時にカウンタがNと一致したら全部取り出せた。else 全部取り出せなかったとなる。

#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  
  vector<queue<int>> cylinder(M);
  
  vector<vector<int>> top_color_location(N + 1);
  
  queue<pair<int, int>> q;
  
  for (int i = 0; i < M; i++) {
    int k;
    cin >> k;
    for (int j = 0; j < k; j++) {
      int a;
      cin >> a;
      cylinder.at(i).push(a);
    }
    top_color_location.at(cylinder.at(i).front()).push_back(i);
  }
  
  for (int i = 1; i <= N; i++) {
    if (top_color_location.at(i).size() == 2) {
      q.push(make_pair(top_color_location.at(i).at(0), top_color_location.at(i).at(1)));
    }
  }
  int cnt = 0;
  
  while (!q.empty()) {
    int beg, end;
    tie(beg, end) = q.front();
    q.pop();
    cylinder.at(beg).pop();
    
    if (!cylinder.at(beg).empty()) {
      int new_color = cylinder.at(beg).front();
      top_color_location.at(new_color).push_back(beg);
      if (top_color_location.at(new_color).size() == 2) {
        int cyl1 = top_color_location.at(new_color).at(0);
        int cyl2 = top_color_location.at(new_color).at(1);
        q.push(make_pair(cyl1, cyl2));
      }
    }
    cylinder.at(end).pop();
    if (!cylinder.at(end).empty()) {
      int new_color = cylinder.at(end).front();
      top_color_location.at(new_color).push_back(end);
      if (top_color_location.at(new_color).size() == 2) {
        int cyl1 = top_color_location.at(new_color).at(0);
        int cyl2 = top_color_location.at(new_color).at(1);
        q.push(make_pair(cyl1, cyl2));
      }
    }
    cnt++;
  }
  
  if (cnt == N) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}