//このコードはACにはならない
//文字の重複を無視しているため、並び替えの個数が違っているのが原因

#include <bits/stdc++.h>
using namespace std;

int main() {
  string st;
  cin >> st;
  int pos;
  cin >> pos;
  vector<char> data;
  for (int i = 0; i < (int)(st.length()); i++) {
    data.push_back(st.at(i));
  }
  
  sort(data.begin(), data.end());
  
  int kaijo1 = 1;
  int kaijo2 = 2;
  int kaijo3 = 6;
  int kaijo4 = 24;
  int kaijo5 = 120;
  int kaijo6 = 720;
  int kaijo7 = 5040;
  
  string ans;
  int curPos = 0;
  
  int insertPos = 0;
  
  while(data.size() > 1) {
    if (data.size() == 8) {
      if (curPos + kaijo7 < pos) {
        curPos += kaijo7;
        insertPos++;
      } else {
        ans += data.at(insertPos);
        data.erase(data.begin() + insertPos);
        insertPos = 0;
      }
    } else if (data.size() == 7) {
      if (curPos + kaijo6 < pos) {
        curPos += kaijo6;
        insertPos++;
      } else {
        ans += data.at(insertPos);
        data.erase(data.begin() + insertPos);
        insertPos = 0;
      }
    } else if (data.size() == 6) {
      if (curPos + kaijo5 < pos) {
        curPos += kaijo5;
        insertPos++;
      } else {
        ans += data.at(insertPos);
        data.erase(data.begin() + insertPos);
        insertPos = 0;
      }
    } else if (data.size() == 5) {
      if (curPos + kaijo4 < pos) {
        curPos += kaijo4;
        insertPos++;
      } else {
        ans += data.at(insertPos);
        data.erase(data.begin() + insertPos);
        insertPos = 0;
      }
    } else if (data.size() == 4) {
      if (curPos + kaijo3 < pos) {
        curPos += kaijo3;
        insertPos++;
      } else {
        ans += data.at(insertPos);
        data.erase(data.begin() + insertPos);
        insertPos = 0;
      }
    } else if (data.size() == 3) {
      if (curPos + kaijo2 < pos) {
        curPos += kaijo2;
        insertPos++;
      } else {
        ans += data.at(insertPos);
        data.erase(data.begin() + insertPos);
        insertPos = 0;
      }
    } else if (data.size() == 2) {
      if (curPos + kaijo1 < pos) {
        curPos += kaijo1;
        insertPos++;
      } else {
        ans += data.at(insertPos);
        data.erase(data.begin() + insertPos);
        insertPos = 0;
      }
    }
  }
  ans += data.at(0);
  cout << ans << endl;
}