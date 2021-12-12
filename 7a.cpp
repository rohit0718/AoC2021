#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const ll INF = 1e17;

int main() {
  int n;
  vector<int> v;
  int mx = 0;
  while (cin >> n) {
    char c; cin >> c;
    v.push_back(n);
    mx = max(mx, n);
  }

  ll res = INF;
  for (int i = 0; i < mx; ++i) {
    ll cur = i;
    ll tmp = 0;
    for (int j = 0; j < v.size(); ++j) {
      tmp += 1LL * abs(v[j] - cur);
    }
    res = min(res, tmp);
  }

  cout << res << "\n";
}

