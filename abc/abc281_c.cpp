// 前も同じようなものをやった気がする abc220_Cとほとんど同じだった。
// 示された数列をsumに足し合わせて、それを使い指定された時間を割り、その答えをsumにかけることで指定された時間弱の値が出る。
// あとは指定された時間を超えるまで数列の値を足し続け、超えたら

#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  long long T;

  cin >> N >> T;

  long long sum = 0;

  vector<long long> data;

  for (int i = 0; i < N; i++)
  {
    long long A;
    cin >> A;
    data.push_back(A);
    sum += A;
  }

  long long cnt = T / sum;
  // cout << cnt << endl;

  long long ans = sum * cnt;

  int idx = -1;

  while (ans < T)
  {
    idx++;
    ans += data.at(idx);
  }

  ans -= T;
  ans = data.at(idx) - ans;
  cout << idx + 1 << " " << ans << endl;
}