#include <iostream>

using namespace std;

const int NUM = 12;

int main() {
  int zeros[NUM] = { 0 };
  string s;
  int num = 0;
  while (cin >> s) {
    num++;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '0') zeros[i]++;
    }
  }
  string gamma = "";
  string epsilon = "";
  for (int i = 0; i < NUM; ++i) {
    if (zeros[i] > num / 2) {
      gamma += '0';
      epsilon += '1';
    } else {
      gamma += '1';
      epsilon += '0';
    }
  }
  cout << stoi(gamma, 0, 2) * stoi(epsilon, 0, 2) << "\n";
}

