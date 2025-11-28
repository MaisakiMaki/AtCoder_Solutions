// 読み込んだ数列を前から右隣より高いか低いかを求め、+か-かの配列を作る。その後その配列を見て、-だったらcntを増やしてmax_cntの更新
// +だったらcntを0にする。最後にmax_cntを求める

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
  int N; cin >> N;
  vector<ll> data;
  vector<string> sum;
  
  rep(i, N) {
    ll n; cin >> n;
    data.pb(n);
  }
  
  rep(i, N - 1) {
    if (data.at(i) >= data.at(i + 1)) {
      sum.pb("-");
    } else {
      sum.pb("+");
    }
  }
  
  ll cnt = 0;
  ll max_cnt = 0;
  rep(i, N - 1) {
    //cout << sum.at(i) << endl;
    if (sum.at(i) == "-") {
      cnt++;
      max_cnt = max(max_cnt, cnt);
    } else {
      cnt = 0;
    }
  }
  cout << max_cnt << endl;
}