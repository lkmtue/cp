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

#define base 1000000007LL
#define MAX 111

ll fac[MAX];
ll c[MAX][MAX], a[MAX][MAX];

ll power(ll x, ll y) {
  if (y == 0) return 1;
  if (y == 1) return x % base;
  ll r = power(x, y / 2);
  r = (r * r) % base;
  if (y % 2 == 1) {
    return (r * x) % base;
  } else {
    return r;
  }
}

ll inv(ll x) {
  return power(x, base - 2);
}

ll C(int n, int k) {
  ll r = (fac[n] * inv(fac[k])) % base;
  return (r * inv(fac[n - k])) % base;
}

ll A(int n, int k) {
  return (fac[n] * inv(fac[n - k])) % base;
}

int main() {
  int t;
  scanf("%d", &t);

  fac[0] = 1;
  FOR (i, 1, 100) fac[i] = (fac[i - 1] * i) % base;

  c[0][0] = 1;
  FOR (n, 1, 100) {
    c[n][0] = 1;
    FOR (k, 1, n) {
      c[n][k] = (c[n - 1][k - 1] + c[n - 1][k]) % base;
    }
  }

  a[0][0] = 1;
  FOR (n, 1, 100) {
    a[n][0] = 1;
    FOR (j, 1, 100) {
      a[n][j] = (a[n][j - 1] * (n - j + 1)) % base;
    }
  }

  while (t--) {
    int n, k;
    scanf("%d%d", &n, &k);
    REP (i, n - 1) {
      int u, v;
      scanf("%d%d", &u, &v);
    }
    ll res = 0;
    FOR (x, 1, k) {
      // res = (res + C(n - 1, x - 1) * A(k, x)) % base;
      res = (res + c[n - 1][x - 1] * a[k][x]) % base;
    }
    cout << res << endl;
  }
}

