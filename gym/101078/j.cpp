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

struct Word {
  int x, y;
  string s;
} hor[MAX], ver[MAX];

vector<int> a[MAX];

int matchX[MAX], matchY[MAX], used[MAX], s;
bool found;
void dfs(int u) {
  used[u] = s;
  REP (i, a[u].size()) {
    int v = a[u][i];
    if (!matchY[v]) found = true;
    else if (used[matchY[v]] != s) dfs(matchY[v]);
    if (found) {
      matchX[u] = v;
      matchY[v] = u;
      return;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  int numt;
  cin >> numt;
  while (numt--) {
    int h, v;
    cin >> h >> v;

    FOR (i, 1, h) cin >> hor[i].x >> hor[i].y >> hor[i].s;
    FOR (i, 1, v) cin >> ver[i].x >> ver[i].y >> ver[i].s;

    FOR (i, 1, v) a[i].clear();

    FOR (i, 1, h) FOR (j, 1, v) {
      int x = ver[j].x;
      int y = hor[i].y;

      if (hor[i].x <= x && x <= hor[i].x + hor[i].s.size() - 1 &&
          ver[j].y <= y && y <= ver[j].y + ver[j].s.size() - 1) {

        char c = hor[i].s[x - hor[i].x];
        char d = ver[j].s[y - ver[j].y];

        if (c != d) a[j].push_back(i);
      }
    }

    memset(matchX, 0, sizeof(matchX));
    memset(matchY, 0, sizeof(matchY));
    memset(used, 0, sizeof(used));
    FOR (u, 1, v) {
      if (!matchX[u]) {
        s = u;
        found = false;
        dfs(u);
      }
    }

    int res = v + h;

    FOR (u, 1, v) {
      if (matchX[u]) {
        res--;
      }
    }

    cout << res << endl;
  }
}

