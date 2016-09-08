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

#define MAX 1000111

int n, q;

int f[MAX][20];
int lg[MAX];

int solve(int x, int y) {
  int i = x;
  int sum = 0;
  while (true) {
    if (f[i][0] == 0 || f[i][0] > y) return sum;

    int j = 0;
    while (f[i][j + 1] != 0 && f[i][j + 1] <= y) j++;

    sum += 1 << j;
    i = f[i][j] + 1;
  }
}

int main() {
  scanf("%d%d", &n, &q);
  int len = 0;

  REP (i, n) {
    int start, end;
    scanf("%d%d", &start, &end);

    len = max(len, end);

    if (f[start][0] == 0 || f[start][0] > end) {
      f[start][0] = end;
    }
  }

  FORD (i, len - 1, 1) {
    if (f[i][0] == 0) {
      f[i][0] = f[i + 1][0];
    } else {
      if (f[i + 1][0] != 0) {
        f[i][0] = min(f[i + 1][0], f[i][0]);
      }
    }
  }

  lg[1] = 0;
  FOR (i, 2, n) {
    if ((1 << (lg[i -1] + 1)) == i) lg[i] = lg[i - 1] + 1;
    else lg[i] = lg[i - 1];
  }

  FOR (j, 1, lg[n]) {
    FOR (i, 1, len) {
      int k = f[i][j - 1];
      if (k != 0) {
        f[i][j] = f[k + 1][j - 1];
      }
    }
  }

  REP (_, q) {
    int x, y;
    scanf("%d%d", &x, &y);
    printf("%d\n", solve(x, y));
  }
}

