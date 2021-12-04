#include <iostream>

using namespace std;

const int INF = 1e9;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  int res = 0;
  int prev = INF;
  while (cin >> n) {
    if (n > prev) res++;
    prev = n;
  }
  cout << res << "\n";
}

