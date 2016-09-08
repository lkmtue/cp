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

#define eq(x, y) (abs(x-y)<1e-7)

int n, t;
double a[20][100000];

void add(int x, int y, double s) {
  if (x == n + 1) {
    return;
  }
  if (s < 1e-7) {
    return;
  }
  if (a[x][y] + s > 1 - 1e-7) {
    double temp = a[x][y] + s - 1;
    a[x][y] = 1;
    add(x + 1, y, temp / 2);
    add(x + 1, y + 1, temp / 2);
  } else {
    a[x][y] = a[x][y] + s;
  }
}

int main() {
  cin >> n >> t;
  add(1, 1, t);

  int res = 0;
  FOR (i, 1, n) {
    FOR (j, 1, 1 << i) {
      if (eq(a[i][j], 1)) {
        res++;
      }
    }
  }

  cout << res << endl;
}

