// なんかシュークリームとかなんとか書いてあるが、結局は約数の列挙
// √nまで割り切れるか調べて割り切れたらdataにpush、その時の相方がその数字じゃなかったらpush

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vpii = vector<pair<int, int>>;
using pii = pair<int, int>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define pb push_back
#define mp make_pair
template<class T> bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; } 
void yes() { cout << "Yes" << endl; } 
void no() { cout << "No" << endl; }

int main() {
  ll N; cin >> N;
  vector<ll> data;
  for (ll i = 1; i * i <= N; i++) {
    if (N % i == 0) {
      data.pb(i);
      if (N / i != i) {
        data.pb(N / i);
      }
    }
  }
  sort(all(data));
  
  rep(i, data.size()) {
    cout << data.at(i) << endl;
  }
}