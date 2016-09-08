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

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int op[] = {2, 3, 0, 1};

int m, n;

typedef pair<pair<int, int>, int> State;

int a[MAX][MAX];
int d[MAX][MAX][4];

void refine(int i) {
  FOR (j, 1, n) {
    if (a[i][j] == '+') a[i][j] = 15;
    else if (a[i][j] == '-') a[i][j] = 10;
    else if (a[i][j] == '|') a[i][j] = 5;
    else if (a[i][j] == '^') a[i][j] = 1;
    else if (a[i][j] == '>') a[i][j] = 2;
    else if (a[i][j] == '<') a[i][j] = 8;
    else if (a[i][j] == 'v') a[i][j] = 4;
    else if (a[i][j] == 'L') a[i][j] = 7;
    else if (a[i][j] == 'R') a[i][j] = 13;
    else if (a[i][j] == 'U') a[i][j] = 14;
    else if (a[i][j] == 'D') a[i][j] = 11;
    else if (a[i][j] == '*') a[i][j] = 0;
  }
}

bool inside(int x, int y) {
  return 1 <= x && x <= m && 1 <= y && y <= n;
}

int bit(int x, int i) {
  return (x >> i) & 1;
}

bool canGo(int x, int y, int r, int k) {
  int i = (k - r + 4) % 4;
  int j = (op[k] - r + 4) % 4;

  int u = x + dx[k];
  int v = y + dy[k];

  return inside(u, v) && bit(a[x][y], i) == 1 && bit(a[u][v], j) == 1;
}

int main() {
  cin >> m >> n;

  FOR (i, 1, m) {
    string s;
    cin >> s;
    s = " " + s;
    FOR (j, 1, n) {
      a[i][j] = s[j];
    }
    refine(i);
  }

  int xs, ys, xf, yf;

  cin >> xs >> ys >> xf >> yf;
  if (xs == xf && ys == yf) {
    cout << 0;
    return 0;
  }

  queue<State> q;

  memset(d, -1, sizeof(d));
  q.push(make_pair(make_pair(xs, ys), 0));
  d[xs][ys][0] = 0;

  while (!q.empty()) {
    State u = q.front();
    q.pop();

    pii pos = u.first;
    int r = u.second;

    int nextR = (r + 1) % 4;
    if (d[pos.first][pos.second][nextR] == -1) {
      d[pos.first][pos.second][nextR] = d[pos.first][pos.second][r] + 1;
      q.push(make_pair(pos, nextR));
    }

    REP (k, 4) {
      if (canGo(pos.first, pos.second, r, k)) {
        pii nextPos(pos.first + dx[k], pos.second + dy[k]);
        if (d[nextPos.first][nextPos.second][r] == -1) {
          d[nextPos.first][nextPos.second][r] = d[pos.first][pos.second][r] + 1;
          q.push(make_pair(nextPos, r));

          if (nextPos.first == xf && nextPos.second == yf) {
            cout << d[nextPos.first][nextPos.second][r];
            return 0;
          }
        }
      }
    }
  }

  cout << -1;
}

