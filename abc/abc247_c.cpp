// 再帰をつかう。Nが1の時は1のみを要素としてもつ配列を返して、それ以外だと左にSN-1 N SN-1を要素として持つ配列を返す。

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

vi S(int N) {
  if (N == 1) return {1};
  vi left = S(N - 1);
  vi ans;
  ans.insert(ans.end(), all(left));
  ans.pb(N);
  ans.insert(ans.end(), all(left));
  return ans;
}

int main() {
  int N; cin >> N;
  vi ans = S(N);
  for (int i = 0; i < ans.size(); i++) {
    cout << ans.at(i);
    if (i != ans.size() - 1) cout << " ";
    else cout << endl;
  }
}