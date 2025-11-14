//一回string型にした後にsortとreverseをしてstollで最大最小をとる。to_stringでsを更新し、それをK回繰り返す。

#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  int K;
  cin >> s >> K;
  
  for (int i = 0; i < K; i++) {
    sort(begin(s), end(s));
  
    long long min_num = stoll(s);
  
    reverse(begin(s), end(s));
  
    long long max_num = stoll(s);
    
    s = to_string(max_num - min_num);
  }
  
  cout << s << endl;
}