//data.at(i) - 1番目がi + 1番目になればいい

#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  vector<int> data;
  
  for (int i = 0; i < N; i++) {
    int n;
    cin >> n;
    data.push_back(n);
  } 
  
  vector<int> ans(2*100000);
  
  
  for (int i = 0; i < N; i++) {
    ans.at(data.at(i) - 1) = i + 1;
  }
  
  for (int i = 0; i < N; i++) {
    cout << ans.at(i);
    if (i == N - 1) {
      cout << endl;
    } else {
      cout << " ";
    }
  }
}