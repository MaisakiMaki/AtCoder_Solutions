// 0未満になるギリギリのところを求め、その時と0未満になった時とでどっちの方が絶対値的に小さいかを求める。

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
  ll N, K; cin >> N >> K;
  
  ll mul = N / K;
  
  N -= mul * K;
  
  ll ans = min(N, abs(N - K));
  
  cout << ans << endl;
}
