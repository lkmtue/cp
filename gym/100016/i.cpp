#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

struct Point {
  double x, y;
  Point(double x = 0, double y = 0) : x(x), y(y) {}

  Point rotate(double sina, double cosa) {
    return Point(x * cosa - y * sina, x * sina + y * cosa);
  }
} a[1111];

bool cmp(const Point &a, const Point &b) {
  return a.x < b.x;
}

int main() {
  freopen("statistics.in", "r", stdin);

  int nrotate = 50000;
  double pi = acos(-1);

  double sina = sin(pi / nrotate);
  double cosa = cos(pi / nrotate);

  int n;
  double d;

  cin >> n >> d;
  for (int i = 0; i < n; i++) {
    cin >> a[i].x >> a[i].y;
  }

  int res = 0;

  for (int t = 0; t < nrotate; t++) {
    sort(a, a + n, cmp);

    int j = 0;

    for (int i = 0; i < n; i++) {
      while (a[j].x < a[i].x - d * 2 - 1e-6) j++;

      res = max(res, i - j + 1);
    }

    for (int i = 0; i < n; i++) {
      a[i] = a[i].rotate(sina, cosa);
    }
  }

  printf("%d\n", res);
}
