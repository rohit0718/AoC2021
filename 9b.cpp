
#include <iostream>
#include <vector>
#include <map>

using namespace std;

const int COLS = 100;
const int ROWS = 100;

long long dfs(int i, int j, vector<vector<int>>& v, map<pair<int,int>,bool>& seen) {
  if (seen[{ i,j }] || v[i][j] == 9) return 0;
  seen[{ i,j }] = 1;
  int tmp = 1;
  int disI[] = { 0,0,1,-1 };
  int disJ[] = { 1,-1,0,0 };
  for (int dir = 0; dir < 4; ++dir) {
    int nextI = i + disI[dir];
    int nextJ = j + disJ[dir];
    if (nextI < 0 || nextI >= ROWS || nextJ < 0 || nextJ >= COLS) continue;
    tmp += dfs(nextI, nextJ, v, seen);
  }
  return tmp;
}

int main() {
  vector<vector<int>> v(ROWS, vector<int>(COLS, 0));
  for (int i = 0; i < ROWS; ++i) {
    for (int j = 0; j < COLS; ++j) {
      char c; cin >> c;
      v[i][j] = c - '0';
    }
  }

  map<pair<int,int>,bool> seen;
  vector<long long> res;
  for (int i = 0; i < ROWS; ++i) {
    for (int j = 0; j < COLS; ++j) {
      res.push_back(dfs(i, j, v, seen));
    }
  }

  sort(res.begin(), res.end(), greater<long long>());

  cout << 1LL * res[0] * res[1] * res[2] << "\n";
}

