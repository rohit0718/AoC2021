#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> v;
  int n;
  while (cin >> n) {
    v.push_back(n);
  }
  int cur = v[0] + v[1] + v[2];
  int res = 0;
  for (int i = 3; i < v.size(); ++i) {
    int next = cur - v[i - 3] + v[i];
    if (cur < next) res++;
    cur = next;
  }
  cout << res << "\n";
}

