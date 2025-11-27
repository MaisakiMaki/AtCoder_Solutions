//逆操作。0~NではなくN~0を作る文字列を生成し、それをreverseすればいい。

#include <bits/stdc++.h>
using namespace std;

int main() {
  long long N;
  cin >> N;
  
  vector<string> data;
  
  while (N > 0) {
    if (N % 2 == 0) {
      data.push_back("B");
      N /= 2;
    } else {
      data.push_back("A");
      N--;
    }
  }
  
  reverse(data.begin(), data.end());
  
  for (int i = 0; i < data.size(); i++) {
    cout << data.at(i);
  }
  cout << endl;
}