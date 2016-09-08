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

#define MAX 111

const ll oo = 1e18;

ll f[MAX][MAX][MAX], g[MAX][MAX][MAX];

int c[MAX];
int a[MAX][MAX];

int main() {
  ios::sync_with_stdio(false);
  int n, m, p;

  while (cin >> n >> m >> p) {
    FOR (i, 1, n) cin >> c[i];
    FOR (i, 1, n) FOR (j, 1, m) cin >> a[i][j];

    FOR (i, 0, MAX - 1) FOR (j, 0, MAX - 1) FOR (k, 0, MAX - 1) f[i][j][k] = oo;

    FOR (k, 1, m) {
      f[0][0][k] = oo;
      g[0][0][k] = 0;
    }

    FOR (i, 1, n) {
      FOR (j, 1, i) {
        FOR (k, 1, m) {
          f[i][j][k] = oo;
          
          if (c[i] == 0) {
            if (i - 1 >= j) {
              f[i][j][k] = min(f[i][j][k], f[i - 1][j][k] + a[i][k]);
            }
            if (j > 1 || i == 1) {
              f[i][j][k] = min(f[i][j][k], g[i - 1][j - 1][k] + a[i][k]);
            }
          } else {
            if (c[i] == k) {
              if (i - 1 >= j) {
                f[i][j][k] = min(f[i][j][k], f[i - 1][j][k]);
              }
              if (j > 1 || i == 1) {
                f[i][j][k] = min(f[i][j][k], g[i - 1][j - 1][k]);
              }
            } else {
              f[i][j][k] = oo;
            }
          }
        }

        g[i][j][1] = oo;
        FOR (k, 2, m) {
          g[i][j][k] = min(g[i][j][k - 1], f[i][j][k - 1]);
        }
        ll t = f[i][j][m];
        FORD (k, m - 1, 1) {
          g[i][j][k] = min(g[i][j][k], t);
          t = min(t, f[i][j][k]);
        }
      }
    }

    ll res = oo;
    FOR (k, 1, m) res = min(res, f[n][p][k]);
    if (res == oo) cout << -1 << endl;
    else cout << res << endl;
  }
}

