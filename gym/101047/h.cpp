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

vector<int> g[MAX], a[MAX];

int matchx[MAX], matchy[MAX], f[MAX], side[MAX], id[MAX];
bool found;
int s;

void dfs(int u) {
  f[u] = s;
  REP (i, a[u].size()) {
    int v = a[u][i];
    if (!matchy[v]) found = true;
    else if (f[matchy[v]] != s) dfs(matchy[v]);
    if (found) {
      matchx[u] = v;
      matchy[v] = u;
      return;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  
  while (t--) {
    int n, m;
    cin >> n >> m;

    FOR (i, 1, n) g[i].clear();

    REP (i, m) {
      int x, y;
      cin >> x >> y;

      g[x].push_back(y);
      g[y].push_back(x);
    }

    queue<int> q;
    q.push(1);
    FOR (i, 1, n) side[i] = -1;
    side[1] = 0;
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      REP (i, g[u].size()) {
        int v = g[u][i];
        if (side[v] == -1) {
          side[v] = 1 - side[u];
          q.push(v);
        }
      }
    }

    int nleft = 0, nright = 0;
    FOR (i, 1, n) {
      if (side[i] == 0) {
        id[i] = ++nleft;
      } else {
        id[i] = ++nright;
      }
    }

    FOR (i, 1, n) {
      if (side[i] == 0) {
        int u = id[i];
        a[u].clear();

        REP (j, g[i].size()) {
          int v = id[g[i][j]];
          a[u].push_back(v);
        }
      }
    }

    memset(f, 0, sizeof(f));
    memset(matchx, 0, sizeof(matchx));
    memset(matchy, 0, sizeof(matchy));

    FOR (u, 1, nleft) {
      if (!matchx[u]) {
        s = u;
        found = false;
        dfs(u);
      }
    }
    int res = 0;
    FOR (u, 1, n) if (matchx[u]) res++;
    cout << n - res << endl;
  }
}

