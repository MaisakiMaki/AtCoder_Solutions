// N * Qでは回せないけど、Qだけだと回せるから、初期値Kの配列にidxがQの場所に1を足していって最後にQの数をO(N)で引いて1以上だったらyesっていうだけ

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

void yes() { cout << "Yes" << endl;}
void no() { cout << "No" << endl;}

int main() {
  int N, Q;
  ll K;
  
  cin >> N >> K >> Q;
  
  vll data(N + 1, K);
  
  for (int i = 0; i < Q; i++) {
    ll n; cin >> n;
    
    data.at(n)++;
  }
  
  for (int i = 1; i < N + 1; i++) {
    data.at(i) -= Q;
    if (data.at(i) > 0) {
      yes();
    } else {
      no();
    }
  }
}