#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
  int n;
  vector<ll> nums(9, 0);
  while (cin >> n) {
    char c; cin >> c;
    nums[n]++;
  }

  int days = 256;
  while (days) {
    ll tmp = nums.front();
    nums.erase(nums.begin());
    nums[6] += tmp;
    nums.push_back(tmp);
    days--;
  }

  ll res = 0;
  for (auto num : nums) {
    res += num;
  }

  cout << res << "\n";
} 

