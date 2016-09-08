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
#define mx(x,y) x=max(x,y)

int n, m, x;
string a, b;

int f[MAX][MAX][11];
int g[MAX][MAX];

int main() {
  cin >> n >> m >> x;
  cin >> a >> b;
  a = " " + a;
  b = " " + b;

  FOR (i, 1, n) {
    FOR (j, 1, m) {
      if (a[i] == b[j]) {
        g[i][j] = g[i - 1][j - 1] + 1;
      } else {
        g[i][j] = 0;
      }
    }
  }

  FOR (i, 0, n) {
    FOR (j, 0, m) {
      int len = g[i][j];

      FOR (k, 0, x) {
        if (k == 0) {
          f[i][j][k] = 0;
        } else {
          f[i][j][k] = -1;
        }

        if (i > 0 && j > 0) {
          FOR (l, 0, k - 1) {
            if (f[i - len][j - len][l] == -1) {
              break;
            }

            if (len + l >= k) {
              mx(f[i][j][k], f[i - len][j - len][l] + len);
            }
          }

          mx(f[i][j][k], f[i - 1][j][k]);
          mx(f[i][j][k], f[i][j - 1][k]);
        }
      }
    }
  }

  cout << f[n][m][x] << endl;
}

