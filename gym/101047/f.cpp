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

#define MAX 2111

struct R {
  R(int x, int y) : x(x), y(y) {}
  int x, y;
};

vector<R> a, b;

bool cmp(R &a, R &b) {
  return (a.x < b.x) || (a.x == b.x && a.y > b.y);
}

bool cmp1(R &a, R &b) {
  int da = -a.x + a.y;
  int db = -b.x + b.y;
  return (da < db) || (da == db && a.x > b.x);
}

bool solve() {
  int n, k;
  ll h;
  cin >> n >> h >> k;

  a.clear();
  b.clear();

  REP (i, n) {
    int x, y;
    cin >> x >> y;
    if (x <= y) {
      a.push_back(R(x, y));
    } else {
      b.push_back(R(x, y));
    }
  }

  sort(a.begin(), a.end(), cmp);

  REP (i, a.size()) {
    if (h > a[i].x) {
      h -= a[i].x;
      h += a[i].y;
    } else {
      if (k == 0) return false;
      k--;
    }
  }

  sort(b.begin(), b.end(), cmp1);

  REP (i, b.size()) {
    if (h > b[i].x) {
      h -= b[i].x;
      h += b[i].y;
    } else {
      if (k == 0) return false;
      k--;
    }
  }

  return true;
}

int main() {
  ios::sync_with_stdio(false);
  int t;
  cin >> t;

  while (t--) {
    cout << (solve() ? "Y" : "N") << endl;
  }
}

