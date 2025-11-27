// 全探索でO(N^2)となってTLEになってしまうことを分配法則を使ってO(N)にした素晴らしい例

#include <bits/stdc++>
using namespace std;

int main() {

  int N;
  cin >> N;

  long long sum = 0;
  vector<int> data;

  for (int i = 0; i < N; i++) {
    int A;
    cin >> A;

    data.push_back(A);
    sum += A;
  }

  long long current = 0;
  long long ans = 0;

  for (int i = 0; i < N; i++) {
    sum -= data.at(i);
    ans += sum * data.at(i);
  }

  cout << ans << endl;

}