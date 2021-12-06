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

  int DAYS = 256;
  while (DAYS) {
    int sz = v.size();
    for (int i = 0; i < sz; ++i) {
      if (!v[i]) {
        v.push_back(8);
        v[i] = 6;
        continue;
      }
      v[i]--;
    }
    DAYS--;
  }
  cout << v.size() << "\n";
} 

