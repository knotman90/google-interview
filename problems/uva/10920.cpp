#include <cmath>
#include <iostream>
#include <vector>

using namespace std;
using Point = pair<int, int>;

enum Direction { UP, LEFT, DOWN, RIGHT, NUM_DIRECTIONS };

inline Direction next_direction(const Direction& dir) {
  return static_cast<Direction>((dir + 1) % NUM_DIRECTIONS);
}

inline Point move(const Point& p, const Direction& dir) {
  Point ans(p);
  switch (dir) {
    case UP:
      ans.first++;
      break;
    case LEFT:
      ans.second--;
      break;
    case DOWN:
      ans.first--;
      break;
    case RIGHT:
      ans.second++;
      break;
  }
  return ans;
}

int main() {
  long sz, p;

  cin >> sz >> p;

  while (sz) {
    Direction dir = UP;

    long start = sqrt(p);
    if (start % 2 == 0) start--;

    p = p - start * start;
    Point c(1 + sz / 2 + start / 2, 1 + sz / 2 + start / 2);

    if (p > 0) {
      long step = 0;
      long leg = 1;

      c = move(c, UP);
      p--;
      dir = LEFT;
      leg = start;

      while (p--) {
        c = move(c, dir);
        step++;
        if (step % leg == 0) {
          step = 0;
          dir = next_direction(dir);
          if (dir == DOWN || dir == UP) leg++;
        }
      }
    }

    cout << "Line = " << c.first << ", column = " << c.second << "." << endl;

    cin >> sz >> p;
  }

  return 0;
}