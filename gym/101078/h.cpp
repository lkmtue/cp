#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FORN(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) for (int i = 0; i < (n); i++)
#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
#define BUG(x) cerr << #x << " = " << x << endl

#define MAX 1111

struct Point {
  int x, y, c;
} a[MAX], g;

int ccw(Point &a, Point &b, Point &c) {
  int ux = b.x - a.x;
  int uy = b.y - a.y;
  int vx = c.x - b.x;
  int vy = c.y - b.y;
  int t = ux * vy - uy * vx;
  if (t < 0) return -1;
  if (t == 0) return 0;
  return 1;
}

bool cmp(Point &u, Point &v) {
  return ccw(g, u, v) > 0;
}

int main() {
  int numt;
  cin >> numt;

  while (numt--) {

    int n;
    cin >> n;
    FOR (i, 1, n) {
      cin >> a[i].x >> a[i].y;
      a[i].c = 0;
    }

    FOR (i, n + 1, n + n) {
      cin >> a[i].x >> a[i].y;
      a[i].c = 1;
    }

    n *= 2;

    int res = 0;

    FOR (i, 1, n) {
      vector<Point> b, c;

      FOR (j, 1, n) if (j != i) {
        if (a[j].y >= a[i].y) {
          b.push_back(a[j]);
        } else {
          c.push_back(a[j]);
        }
      }

      g = a[i];
      sort(b.begin(), b.end(), cmp);
      sort(c.begin(), c.end(), cmp);

      for (auto &p : c) b.push_back(p);
      
      int color[2] = { 0, 0 };
      color[g.c] = 1;

      int j = -1;
      REP (k, b.size()) {
        while (j == -1 || (j + 1 < b.size() && ccw(g, b[k], b[(k + j + 1) % b.size()]) > 0)) {
          j++;
          color[b[(k + j) % b.size()].c]++;
        }

        if (color[0] == n / 4 && color[1] == n / 4) {
          cout << g.x << " " << g.y << " " << b[k].x << " " << b[k].y << endl;
          res++;
        }

        color[b[k].c]--;

        j--;

        if (j < 0) j = 0;
      }
    }

    cout << res / 2 << endl;
  }
}

