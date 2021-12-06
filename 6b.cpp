#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  long long NUMS[9] = { 0 };
  while (cin >> n) {
    char c; cin >> c;
    NUMS[n]++;
  }

  int DAYS = 256;
  while (DAYS) {
    long long NEW_NUMS[9] = { 0 };
    for (int i = 0; i < 9; ++i) {
      if (!i) {
        NEW_NUMS[8] += NUMS[i];
        NEW_NUMS[6] += NUMS[i];
        NUMS[i] = 0;
        continue;
      }
      NEW_NUMS[i - 1] += NUMS[i];
    }
    for (int i = 0; i < 9; ++i) {
      NUMS[i] = NEW_NUMS[i];
    }
    DAYS--;
  }
  long long res = 0;
  for (int i = 0; i < 9; ++i) {
    res += 1LL * NUMS[i];
  }
  cout << res << "\n";
} 

