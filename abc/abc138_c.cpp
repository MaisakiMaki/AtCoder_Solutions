// dataの配列を作った後、sortして前から計算する。後ろには平均化したくない大きい数字があるため、小さい数から平均化していく。

#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  vector<double> data;
  
  for (int i = 0; i < N; i++) {
    double v;
    cin >> v;
    data.push_back(v);
  }
  
  sort(begin(data), end(data));
  
  while(data.size() > 1) {
    double ins = (data.at(0) + data.at(1)) / 2.0;
    data.erase(begin(data), begin(data) + 2);
    //cout << "after_erase: " << data.size() << endl;
    data.push_back(ins);
    sort(begin(data), end(data));
  }
  
  double ans = data.at(0);
  
  printf("%.5lf", ans);
}