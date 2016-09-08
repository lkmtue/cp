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

#define MAX 100111

int n;
ll r, w, h;

struct Point {
  ll x, y;
} a[MAX];

bool cmp(Point &a, Point &b) {
  return a.x < b.x || (a.x == b.x && a.y < b.y);
}

int tree[1000111];
int cnt;

void update(int x, int v) {
  while (x <= cnt) {
    tree[x] = max(tree[x], v);
    x += x & (-x);
  }
}

int get(int x) {
  if (x <= 0) return 0;
  int res = 0;
  while (x) {
    res = max(res, tree[x]);
    x -= x & (-x);
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin >> n >> r >> w >> h;

  map <ll, int> v;

  FOR (i, 1, n) {
    ll x, y;
    cin >> x >> y;
    x *= r;
    a[i].x = x + y;
    a[i].y = y - x;

    v[a[i].x] = 0;
    v[a[i].y] = 0;
  }

  for (auto &p : v) {
    p.second = ++cnt;
  }

  FOR (i, 1, n) {
    a[i].x = v[a[i].x];
    a[i].y = v[a[i].y];
  }

  sort(a + 1, a + n + 1, cmp);

  int res = 0;
  FOR (i, 1, n) {
    int f = get(a[i].y) + 1;
    res = max(res, f);
    update(a[i].y, f);
  }
  cout << res << endl;
}

