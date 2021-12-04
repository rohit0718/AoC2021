#include <iostream>

using namespace std;

int main() {
  int hor = 0, dep = 0, aim = 0;
  string s;
  while (cin >> s) {
    int n; cin >> n;
    if (s == "forward") {
      hor += n;
      dep += aim * n;
    }
    else if (s == "up") aim -= n;
    else aim += n;
  }
  cout << hor * dep << "\n";
}

