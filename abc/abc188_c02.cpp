// トーナメントの左と右で最強を決めてバトらせた方が早いという案。
// powはN - 1とすることで半分の人数でトーナメントをさせることができる。
// あとはnumを使ってfor文を回して右最強と左最強を決めて決勝戦で負けた方のidxを出力すれば終わり

#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  int num = pow(2, N - 1);
  
  long long fstmaxnum = -1;
  int fstidx = 0;
  
  
  for (int i = 0; i < num; i++) {
    int A;
    cin >> A;
    
    if (fstmaxnum < A) {
      fstmaxnum = A;
      fstidx = i + 1;
    }
  }
  
  int scdmaxnum = -1;
  int scdidx = 0;
  
  for (int i = num; i < num * 2; i++) {
    int A;
    cin >> A;
    
    if (scdmaxnum < A) {
      scdmaxnum = A;
      scdidx = i + 1;
    }
  }
  
  if (fstmaxnum > scdmaxnum) {
    cout << scdidx << endl;
  } else {
    cout << fstidx << endl;
  }
}