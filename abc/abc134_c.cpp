// 数列の最大値は最大値を持つidxの時以外は変わらない。
// そのため、基本的にはdataをsortした後、一番後ろを出力して、最大値と同じidxだったらその一個前を見る

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
  
  vpii data;
  
  rep(i, N) {
    int n; cin >> n;
    data.pb(mp(n, i));
  }
  sort(all(data));
  
  rep(i, N) {
    if (i == data.at(N - 1).second) cout << data.at(N - 2).first << endl;
    else cout << data.at(N - 1).first << endl;
  }
}