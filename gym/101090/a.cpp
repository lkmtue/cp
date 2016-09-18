#include <algorithm>
#include <cmath>
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

#define MAX 15111

struct Point {
  ll x, y;
  int id;
} a[MAX];

int top;
Point s[MAX];

int ccw(Point &a, Point &b, Point &c) {
  ll ux = b.x - a.x;
  ll uy = b.y - a.y;
  ll vx = c.x - b.x;
  ll vy = c.y - b.y;
  ll t = ux * vy - uy * vx;
  if (t < 0) return -1;
  if (t == 0) return 0;
  return 1;
}

bool cmp(Point &u, Point &v) {
  return ccw(a[1], u, v) == 1;
}

pair<pair<int, int>, int> iii(int x, int y, int z) {
  return make_pair(make_pair(x, y), z);
}

int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  FOR (i, 1, n) {
    cin >> a[i].x >> a[i].y;
    a[i].id = i;
  }

  int g = 1;
  FOR (i, 1, n) {
    if (a[i].y < a[g].y || (a[g].y == a[i].y && a[i].x < a[g].x)) {
      g = i;
    }
  }
  swap(a[g], a[1]);
  sort(a + 2, a + n + 1, cmp);

  s[++top] = a[1];
  s[++top]= a[2];

  vector<pair<pair<int, int>, int>> res;

  FOR (i, 3, n) {
    res.push_back(iii(a[1].id, s[top].id, a[i].id));
    while (top >= 2 && ccw(s[top - 1], s[top], a[i]) <= 0) {
      res.push_back(iii(s[top - 1].id, s[top].id, a[i].id));
      top--;
    }
    s[++top] = a[i];
  }

  cout << res.size() << endl;
  for (auto p : res) {
    cout << p.first.first << " " << p.first.second << " " << p.second << endl;
  }
}

