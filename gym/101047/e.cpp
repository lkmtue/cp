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

const int dx[] = { -1, 0, 1, 0 };
const int dy[] = { 0, 1, 0, -1 };

struct Cell {
  Cell() : x(0), y(0) {}
  Cell(int x, int y) : x(x), y(y) {}
  int x, y;
};

int m, n;
string a[MAX];

Cell start;
Cell finish;

int walk[MAX][MAX], fire[MAX][MAX];

bool visited[MAX][MAX];

bool inside(Cell u) {
  return 1 <= u.x <= m && 1 <= u.y && u.y <= n;
}

void bfs(char start, int d[][MAX]) {
  queue<Cell> q;

  FOR (i, 1, m) FOR (j, 1, n) {
    d[i][j] = -1;
    if (a[i][j] == start) q.push(Cell(i, j));
  }

  while (!q.empty()) {
    Cell u = q.front();
    q.pop();
    REP (k, 4) {
      Cell v(u.x + dx[k], u.y + dy[k]);
      if (inside(v) && a[v.x][v.y] != '#' && d[v.x][v.y] == -1) {
        d[v.x][v.y] = d[u.x][u.y] + 1;
        q.push(v);
      }
    }
  }
}

bool solve() {
  queue<Cell> q;
  q.push(start);

  FOR (i, 1, m) FOR (j, 1, n) visited[i][j] = false;
  visited[start.x][start.y] = true;

  while (!q.empty()) {
    Cell u = q.front();
    q.pop();
    REP (k, 4) {
      Cell v(u.x + dx[k], u.y + dy[k]);
      if (inside(v) && a[v.x][v.y] != '#' && walk[v.x][v.y] < fire[v.x][v.y] && !visited[v.x][v.y]) {
        visited[v.x][v.y] = true;
        q.push(v);

        if (v.x == finish.x && v.y == finish.y) {
          return true;
        }
      }
    }
  }

  return false;
}

int main() {
  int numt;
  cin >> numt;

  while (numt--) {
    cin >> m >> n;

    FOR (i, 1, m) {
      cin >> a[i];
      a[i] = " " + a[i];

      FOR (j, 1, n) {
        if (a[i][j] == 'S') {
          start = Cell(i, j);
        }

        if (a[i][j] == 'E') {
          finish = Cell(i, j);
        }
      }
    }

    bfs('S', walk);
    bfs('F', fire);

    cout << (solve() ? "Y" : "N") << endl;
  }
}

