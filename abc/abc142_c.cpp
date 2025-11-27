// 217とマジで同じ 舐めてるのか

#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  vector<int> data;
  
  for (int i = 0; i < N; i++) {
    int A;
    cin >> A;
    data.push_back(A);
  }
  
  vector<int> ans(N);
  
  for (int i = 0; i < N; i++) {
    ans.at(data.at(i) - 1) = i + 1;
  }
  
  for (int i = 0; i < N; i++) {
    cout << ans.at(i);
    if (i < N - 1) {
      cout << " ";
    } else {
      cout << endl;
    }
  }
}