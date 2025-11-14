// 最小公倍数を使うだけ

#include <bits/stdc++.h>
using namespace std;

int main() {
  long long A, B;
  cin >> A >> B;
  
  long long ans = lcm(A, B);
  
  cout << ans << endl;
}