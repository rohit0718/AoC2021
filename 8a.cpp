#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<string> v1, v2;
  string s;
  while (cin >> s) {
    if (s == "|") {
      for (int i = 0; i < 4; ++i) {
        cin >> s;
        v2.push_back(s);
      }
      continue;
    }
    v1.push_back(s);
  }

  int res = 0;
  for (string& s : v2) {
    int x = s.size();
    if (x == 2 || x == 3 || x == 7 || x == 4) res++;
  }
  cout << res << "\n";
}

