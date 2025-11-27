// 最終的に出す高さの合計は「一番上の人以外の肩の高さ + 一番上の巨人の頭の高さ」で出せるが、これを変形すると
// 「全員の肩の高さ + (一番上の巨人の頭の高さ - 一番上の肩の高さ)」であり、(一番上の巨人の頭の高さ - 一番上の肩の高さ)が最大になる時が
// 巨人タワーが最大になる時である

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vpii = vector<pair<int, int>>;
using vpll = vector<pair<ll, ll>>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
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
  
  vpll data;
  ll sum_A = 0;
  rep(i, N) {
    ll A, B; cin >> A >> B;
    data.pb(mp(A, B));
    sum_A += A;
  }
  
  sort(all(data));
  reverse(all(data));
  ll ans_height = 0;
  rep(i, N) {
    ll current_height = sum_A + data.at(i).second - data.at(i).first;
    chmax(ans_height, current_height);
  }
  cout << ans_height << endl;
}