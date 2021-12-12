#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
  map<pair<int,int>,int> m;
  int x1, y1, x2, y2;
  int maxX = 0, maxY = 0;
  while (scanf("%d,%d -> %d,%d", &x1, &y1, &x2, &y2) != EOF) {
    maxX = max(maxX, max(x1, x2));
    maxY = max(maxY, max(y1, y2));
    int disX = (x2 > x1) - (x2 < x1);
    int disY = (y2 > y1) - (y2 < y1);
    while (1) {
      m[{ x1,y1 }]++;
      if (x1 == x2 && y1 == y2) break;
      x1 += disX;
      y1 += disY;
    }
  }

  int res = 0;
  for (int y = 0; y <= maxY; ++y) {
    for (int x = 0; x <= maxX; ++x) {
      if (m[{ x,y }] > 1) res++;
    }
  }

  printf("%d\n", res);
}

