#include <iostream>

using namespace std;

int main() {
  int hor = 0, dep = 0;
  string s;
  while (cin >> s) {
    int n; cin >> n;
    if (s == "forward") hor += n;
    else if (s == "up") dep -= n;
    else dep += n;
  }
  cout << hor * dep << "\n";
}

