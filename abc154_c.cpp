// mapで被りの有無を見る、setで見てNとsize比較の方がいい。

#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  map<long long, int> data;
  
  bool is_ok = true;
  
  for (int i = 0; i < N; i++) {
    long long A;
    cin >> A;
    if (data.count(A)) {
      is_ok = false;
      break;
    } else {
      data[A] = 1;
    }
  }
  if (is_ok) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}