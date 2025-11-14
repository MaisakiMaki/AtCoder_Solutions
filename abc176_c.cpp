// Nが2*10^5のため線形可能。maxからdata.at(i)を引いたものが足された値である。long longを使うのだけ注意。

#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  vector<long long> data;
  long long max = 0;
  
  long long plus = 0;
  
  for (int i = 0; i < N; i++) {
    int A;
    cin >> A;
    data.push_back(A);
  }
  
  for (int i = 0; i < N; i++) {
    if (i == 0) {
      max = data.at(0);
    } else {
      if (max > data.at(i)) {
        plus += max - data.at(i);
        data.at(i) = max;
      } else {
        max = data.at(i);
      }
    }
  }
  
  cout << plus << endl;
}