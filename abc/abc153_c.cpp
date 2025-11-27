// Nが2 * 10^5のため、線形可能。dataをsortした後、前からN - K - 1までの値を足していけばいい。Hの最大値が10^9のため、long long型にする。

#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K;
  
  cin >> N >> K;
  
  vector<int> data;
  
  for (int i = 0; i < N; i++) {
    int H;
    cin >> H;
    data.push_back(H);
  }
  
  sort(begin(data), end(data));
  
  
  long long cnt = 0;
  
  for (int i = 0; i < N - K; i++) {
    cnt += data.at(i);
  }
  
  cout << cnt << endl;
}