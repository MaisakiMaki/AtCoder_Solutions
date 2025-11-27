// トーナメントをシミュレーションする。int型とlong long型が格納されたpair型を2つ格納したpair型用のqueueを用意し、それを使ってトーナメントを行う。
// Nは2の累乗数であるため、pow(2,N)で選手全員の人数を知る必要がある。
// long longは選手の力、intは選手番号であり、比べるのはlong longの方(data.front().~.second)
// queueが用意できたらあとはqueueの要素をpopして、二つの選手のパワーを比べ1回目に勝った方をfstwin,2回目に勝った方をscdwinとし、
// その二つでpairを作ってqueueにpushする。決勝戦はscdwinができないため、data.empty()でbreakさせる。
// 負けた方の選手番号をansidxとして保存してあるため、breakしたらansidxを出力して終わり。

#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  int num = pow(2,N);
  
  queue<pair<pair<int, long long>, pair<int, long long>>> data;
  
  int fst = 0;
  int scd = 0;
  
  for (int i = 0; i < num; i++) {
    if (i % 2 == 0) {
      cin >> fst;
    } else {
      cin >> scd;
      data.push(make_pair(make_pair(i, fst), make_pair(i + 1, scd)));
      //cout << "ooookkkk" << endl;
    }
  }
  
  pair<int, long long> fstwin;
  pair<int, long long> scdwin;
  int ansidx = 0;
  
  
  while(1) {
    if (data.front().first.second >  data.front().second.second) {
      fstwin = data.front().first;
      //cout << data.front().first.first << endl;
      ansidx = data.front().second.first;
    } else {
      fstwin = data.front().second;
      //cout << data.front().second.first << endl;
      ansidx = data.front().first.first;
    }
    data.pop();
    if (data.empty()) {
      //cout << "ok" << endl;
      break;
    }
    if (data.front().first.second >  data.front().second.second) {
      scdwin = data.front().first;
      //cout << data.front().first.first << endl;
    } else {
      scdwin = data.front().second;
      //cout << data.front().second.first << endl;
    }
    data.pop();
    data.push(make_pair(fstwin, scdwin));
  }
  cout << ansidx << endl;
}