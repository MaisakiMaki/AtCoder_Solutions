// 3辺の和が等しい時、直方体は立方体の時に体積が最大となるため、Nを3で割り、それを3乗するだけ。
// 全探索は無限の択がある。
// printfを使わないとe表示されてしまうためよくない。

#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  double side = N / 3.0;
  
  double ans = side * side * side;
  
  printf("%.6lf", ans);
}