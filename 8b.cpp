#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

/*
 *    0
 *  1   2
 *    3
 *  4   5
 *    6
 *
 *  Represents the segments turned on for numbers 0 through 9.
 */
vector<vector<int>> NUMS = {
  { 0,1,2,4,5,6 },
  { 2,5 },
  { 0,2,3,4,6 },
  { 0,2,3,5,6 },
  { 1,2,3,5 },
  { 0,1,3,5,6 },
  { 0,1,3,4,5,6 },
  { 0,2,5 },
  { 0,1,2,3,4,5,6 },
  { 0,1,2,3,5,6 }
};

bool check(int val, string& s) {
  return NUMS[val].size() == s.size();
}

ll getVal(vector<string>& v1, vector<string>& v2, vector<char>& pos) {
  ll res = 0;
  for (string& s : v2) {
    // which digit is s?
    for (int i = 0; i < 10; ++i) {
      string tmp = "";
      for (int j : NUMS[i]) {
        tmp += pos[j];
      }
      sort(tmp.begin(), tmp.end());
      if (tmp == s) {
        res = (res + i) * 10; // s represents i!
        break;
      }
    }
  }
  return res / 10;
}

ll solve(vector<string>& v1, vector<string>& v2) {
  vector<char> pos = { 'a','b','c','d','e','f','g' };
  // brute force all combinations of display segments
  // guaranteed to find a satisfying assignment
  do {
    bool can = true;
    for (int i = 0; i < 10 && can; ++i) {
      string tmp = "";
      for (int j : NUMS[i]) {
        tmp += pos[j];
      }
      sort(tmp.begin(), tmp.end());
      bool found = false;
      for (string &s : v1) {
        if (s == tmp) found = true;
      }
      if (!found) can = false;
    }
    if (can) {
      return getVal(v1, v2, pos);
    }
  } while (next_permutation(pos.begin(), pos.end()));

  cout << "FAIL\n";
  return -1;
}

int main() {
  vector<string> v1, v2;
  string s;
  ll res = 0;
  while (cin >> s) {
    if (s == "|") {
      for (int i = 0; i < 4; ++i) {
        cin >> s;
        sort(s.begin(), s.end());
        v2.push_back(s);
      }
      res += solve(v1, v2);
      v1.clear();
      v2.clear();
      continue;
    }
    sort(s.begin(), s.end());
    v1.push_back(s);
  }

  cout << res << "\n";
}

