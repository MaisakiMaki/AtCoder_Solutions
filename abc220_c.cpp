// 10^100も探索できないので全探索は無理。Ai,Xは10^9超えるのでそこら辺の数字を入れる時は、long long指定が確定。
// Aの数列を入れる時にsumも一緒に計算。その後Xをsumで割ったものをカウンタとして設定。
// また、sumとカウンタを掛けたtmpはXより小さい値、もしくは同じ値であり、そこからdataの要素をいくつか足していくことで出力するものが出る。
// また、tmpの値はdataの要素数とカウンタを掛けた数分の要素数を足したものであるため、それをansと設定し、そこからいくつ要素数を足して行ったらXを超えるかを
// カウンタをリセットした後にカウンタで数え、超えた段階でwhilebreak。ansにカウンタを足せば終わり。

#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  vector<long long> data;
  
  long long sum = 0;
  
  for (int i = 0; i < N; i++) {
    long long A;
    cin >> A;
    data.push_back(A);
    sum += A;
  }
  //cout << "sum: " << sum << endl;
  
  long long X;
  cin >> X;
  
  long long cnt = (X / sum);
  
  //cout << cnt << endl;
  
  long long tmp = sum * cnt;
  
  long long ans = data.size() * cnt;
  
  cnt = 0;
  
  while (1) {
    cnt++;
    tmp += data.at(cnt - 1);
    //cout << "tmp: " << tmp << endl;
    if (tmp > X) {
      break;
    }
    
  }
  
  ans += cnt;
  cout << ans << endl;
}