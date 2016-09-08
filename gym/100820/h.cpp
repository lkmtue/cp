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

#define MAX 200111

int n, s;

struct Point {
  Point() {}
  Point(int x, int y, int id) : x(x), y(y), id(id) {}
  int x, y, id;
};

string name[MAX];

void sort(vector<Point> &ps) {
  if (ps.size() <= 1) return;

  vector<Point> a, b, c, d;

  for (auto p : ps) {
    int x = p.x, y = p.y, id = p.id;

    if (x * 2 < s && y * 2 < s) {
      a.push_back(Point(y * 2, x * 2, id));
    } else if (x * 2 < s && y * 2 > s) {
      b.push_back(Point(x * 2, y * 2 - s, id));
    } else if (x * 2 > s && y * 2 > s) {
      c.push_back(Point(x * 2 - s, y * 2 - s, id));
    } else if (x * 2 > s && y * 2 < s) {
      d.push_back(Point(s - y * 2, s * 2 - x * 2, id));
    }
  }

  sort(a);
  sort(b);
  sort(c);
  sort(d);

  ps.clear();
  for (auto p : a) ps.push_back(p);
  for (auto p : b) ps.push_back(p);
  for (auto p : c) ps.push_back(p);
  for (auto p : d) ps.push_back(p);
}

int main() {
  cin >> n >> s;
  vector<Point> ps;
  REP (i, n) {
    Point p;
    cin >> p.x >> p.y >> name[i];
    p.id = i;
    ps.push_back(p);
  }

  sort(ps);

  REP (i, ps.size()) {
    cout << name[ps[i].id] << endl;
  }
}

