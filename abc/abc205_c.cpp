// cが偶数だったら絶対値の大小関係、奇数だったらその値の大小関係

#include <bits/stdc++.h>

using namespace std;

void compare(long long A, long long B) {
  if (abs(A) < abs(B)) {
      cout << "<" << endl;
    } else if (abs(A) > abs(B)) {
      cout << ">" << endl;
    } else {
      cout << "=" << endl;
    }
}

int main() {

  long long A, B, C;
  cin >> A >> B >> C;
  
  if (C % 2 == 0) {
    compare(A, B);
  } else {
    if (A > B) {
      cout << ">" << endl;
    } else if (A < B) {
      cout << "<" << endl;
    } else {
      cout << "=" << endl;
    }
  }
}