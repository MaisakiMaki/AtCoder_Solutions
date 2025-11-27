// 全探索だと10^10になるため不可。Nが確実に2nになるため、N/2と(N/2) + 1の時のdataの差を取れば出る。

#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  vector<int> data;
  
  for (int i = 0; i < N; i++) {
    int d;
    cin >> d;
    data.push_back(d);
  }
  
  sort(begin(data), end(data));
  
  int cent = N / 2;
  
  int bef = data.at(cent - 1);
  int aft = data.at(cent);
  
  cout << aft - bef << endl;
}