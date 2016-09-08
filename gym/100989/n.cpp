#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

#define oo 1000111000
#define MAXN 511
#define PIII pair<int, pair<int, int> >

#define MAXN 511

int m, n;
int a[MAXN][MAXN], d[MAXN][MAXN];

int main() {
  cin >> m >> n;

  priority_queue<PIII > q;

  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      d[i][j] = oo;
      cin >> a[i][j];
      if (i == 1 || j == 1 || i == m || j == n) {
        d[i][j] = a[i][j];
        q.push(make_pair(-a[i][j], make_pair(i, j)));
      }
    }
  }

  while (!q.empty()) {
    PIII t = q.top();
    q.pop();
    int u = t.second.first;
    int v = t.second.second;
    if (d[u][v] != -t.first) {
      continue;
    }

    for (int k = 0; k < 4; k++) {
      int x = u + dx[k];
      int y = v + dy[k];
      int l = max(a[x][y], d[u][v]);
      if (d[x][y] > l) {
        d[x][y] = l;
        q.push(make_pair(-l, make_pair(x, y)));
      }
    }
  }

  long long res = 0;
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      res += d[i][j] - a[i][j];
    }
  }

  cout << res << endl;
}
