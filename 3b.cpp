#include <iostream>
#include <vector>

using namespace std;

const int NUM = 12;

int main() {
  string s;
  vector<string> oxygen;
  while (cin >> s) {
    oxygen.push_back(s);
  }
  vector<string> co2 = oxygen;

  // fill up oxygen first
  for (int i = 0; i < NUM; ++i) {
    vector<string> newOxygen;
    int zeros = 0;
    for (int j = 0; j < oxygen.size(); ++j) {
      if (oxygen[j][i] == '0') zeros++;
    }
    for (int j = 0; j < oxygen.size(); ++j) {
      if (zeros > oxygen.size() / 2) {
        if (oxygen[j][i] == '0') {
          newOxygen.push_back(oxygen[j]);
        }
        continue;
      }
      if (oxygen[j][i] == '1') {
        newOxygen.push_back(oxygen[j]);
      }
    }
    oxygen = newOxygen;
  }

  // fill up co2
  for (int i = 0; i < NUM; ++i) {
    vector<string> newCo2;
    int zeros = 0;
    for (int j = 0; j < co2.size(); ++j) {
      if (co2[j][i] == '0') zeros++;
    }
    for (int j = 0; j < co2.size(); ++j) {
      if (zeros <= co2.size() / 2) {
        if (co2[j][i] == '0') {
          newCo2.push_back(co2[j]);
        }
        continue;
      }
      if (co2[j][i] == '1') {
        newCo2.push_back(co2[j]);
      }
    }
    co2 = newCo2;
  }

  cout << stoi(oxygen[0], 0, 2) * stoi(co2[0], 0, 2) << "\n";
}

