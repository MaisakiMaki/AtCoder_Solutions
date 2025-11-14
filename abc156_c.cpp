//Nが100しかなく、位置も100までしかないため100人に対して100の位置を出しても10^4の計算しかしない。平均を出すより全探索した方が安全。

#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  vector<int> data;
  int sum = 0;
  
  for (int i = 0; i < N; i++) {
    int n;
    cin >> n;
    data.push_back(n);
    sum += n;
  }
  
  long long min_ans = 2000000000;
  
  for (int i = 1; i <= 100; i++) {
    long long ans = 0;
    for (int j = 0; j < N; j++) {
      int n = pow((data.at(j) - i), 2);
      ans += n;
    }
    min_ans = min(ans, min_ans);
  }
  cout << min_ans << endl;
}