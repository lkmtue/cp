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

#define base 1000000007

ll n;

int f[70][2][70][2];

int a[70];

void init() {
  REP(i, 64) {
    a[i] = (n >> i) & 1;
  }
}

void inc(int &x, int y) {
  x += y;
  if (x >= base) x -= base;
}

int calc(int i, int sm, int j, int bitI) {
  int &res = f[i][sm][j][bitI];
  if (res != -1) {
    return res;
  } else if (i == 0) {
    if (j == 0) {
      res = 1;
    } else {
      res = 0;
    }
    return res;
  } else {
    int maxD;

    if (sm == 1) {
      maxD = 1;
    } else {
      maxD = a[i - 1];
    }

    res = 0;

    FOR (d, 0, maxD) {
      int nextSm;
      if (sm == 1) {
        nextSm = 1;
      } else {
        if (d < a[i - 1]) {
          nextSm = 1;
        } else {
          nextSm = 0;
        }
      }

      int nextJ;
      if (bitI != d) {
        nextJ = j - 1;
      } else {
        nextJ = j;
      }

      if (nextJ >= 0) {
        inc(res, calc(i - 1, nextSm, nextJ, d));
      }
    }

    return res;
  }
}

ll get(int n) {
  int last = 0;
  ll x = 0;
  FOR (i, 1, n) {
    last = 1 - last;
    x = x * 2 + last;
  }
  return x % base;
}

int main() {
  while (cin >> n) {
    memset(f, -1, sizeof(f));
    memset(a, 0, sizeof(a));
    init();

    ll res = 0;
    FOR(j, 1, 63) {
      int temp = calc(65, 0, j, 0);
      res = (res + temp * get(j)) % base;
    }
    cout << res << endl;
  }
}

