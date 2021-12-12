#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef long long ll;

const int MOD = 10;
const int LEN = 10;
const int STEPS = 100;

ll propagate(int i, int j, vector<vector<int>>& v, map<pair<int,int>,bool>& seen) {
  if (seen[{ i,j }] || v[i][j]) return 0;
  seen[{ i,j }] = 1;
  int disX[] = { -1,0,1 };
  int disY[] = { -1,0,1 };
  ll flashes = 1;
  for (int x = 0; x < 3; ++x) {
    for (int y = 0; y < 3; ++y) {
      int neighX = j + disX[x];
      int neighY = i + disY[y];
      if (neighX < 0 || neighX >= LEN || neighY < 0
            || neighY >= LEN || !v[neighY][neighX]) {
        continue;
      }
      v[neighY][neighX] = (v[neighY][neighX] + 1) % MOD;
      flashes += propagate(neighY, neighX, v, seen);
    }
  }
  return flashes;
}

int main() {
  vector<vector<int>> v(LEN, vector<int>(LEN));
  for (int i = 0; i < LEN; ++i) {
    for (int j = 0; j < LEN; ++j) {
      char c; cin >> c;
      v[i][j] = c - '0';
    }
  }
  ll flashes = 0;
  for (int step = 0; step < STEPS; ++step) {
    for (int i = 0; i < LEN; ++i) {
      for (int j = 0; j < LEN; ++j) {
        v[i][j] = (v[i][j] + 1) % MOD;
      }
    }
    map<pair<int,int>,bool> seen;
    for (int i = 0; i < LEN; ++i) {
      for (int j = 0; j < LEN; ++j) {
        flashes += propagate(i, j, v, seen);
      }
    }
  }
  cout << flashes << "\n";
}

