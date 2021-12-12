#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  vector<int> v;
  while (cin >> n) {
    char c; cin >> c;
    v.push_back(n);
  }

  int days = 80;
  while (days) {
    int sz = v.size();
    for (int i = 0; i < sz; ++i) {
      if (!v[i]) {
        v.push_back(8);
        v[i] = 6;
        continue;
      }
      v[i]--;
    }
    days--;
  }

  cout << v.size() << "\n";
} 

