// さすがにO(N^2)で回せるわけがないので、O(N)で済むように頑張る
// K / Nをすることで、キャンディーを何周して渡すかが出る。その後、K %= NでK回ループさせることで、最大N - 1回のループで済むようになる。

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
  int N;
  ll K;
  cin >> N >> K;
  
  vector<pair<ll, int>> data;
  
  rep(i, N) {
    ll a; cin >> a;
    data.pb(mp(a, i));
  }
  
  sort(all(data));
  
  ll plus = K / N;
  K %= N;
  vector<ll> ans(N, 0);
  
  rep(i, N) {
    ans.at(data.at(i).second) += plus;
    if (K > 0) ans.at(data.at(i).second)++;
    K--;
  }
  
  rep(i, N) {
    cout << ans.at(i) << endl;
  }
}