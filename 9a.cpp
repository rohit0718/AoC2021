#include <iostream>
#include <vector>

using namespace std;

const int COLS = 100;
const int ROWS = 100;

bool isPeak(int i, int j, vector<vector<int>>& v) {
  int disI[] = { 0,0,1,-1 };
  int disJ[] = { 1,-1,0,0 };
  for (int dir = 0; dir < 4; ++dir) {
    int nextI = i + disI[dir];
    int nextJ = j + disJ[dir];
    if (nextI < 0 || nextI >= ROWS || nextJ < 0 || nextJ >= COLS) continue;
    if (v[nextI][nextJ] <= v[i][j]) return false;
  }
  return true;
}

int main() {
  vector<vector<int>> v(ROWS, vector<int>(COLS, 0));
  for (int i = 0; i < ROWS; ++i) {
    for (int j = 0; j < COLS; ++j) {
      char c; cin >> c;
      v[i][j] = c - '0';
    }
  }

  long res = 0;
  for (int i = 0; i < ROWS; ++i) {
    for (int j = 0; j < COLS; ++j) {
      if (isPeak(i, j, v)) {
        res += 1 + v[i][j];
      }
    }
  }

  cout << res << "\n";
}

