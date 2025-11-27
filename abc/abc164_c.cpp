//setで被りを禁止するだけ

#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  set<string> data;
  
  for (int i = 0; i < N; i++) {
    string s;
    cin >> s;
    data.insert(s);
  }
  
  cout << data.size() << endl;
}