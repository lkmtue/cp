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

#define MAX 511

struct Flight {
  int from, to;
  int time;
} flight[MAX];

int n, m;
int p[MAX], a[MAX][MAX], d[MAX][MAX];

int used[MAX], s, matchX[MAX], matchY[MAX];
bool found;
vector<int> g[MAX];

void dfs(int u) {
  used[u] = s;

  REP (i, g[u].size()) {
    int v = g[u][i];

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

  cin >> n >> m;
  FOR (i, 1, n) {
    cin >> p[i];
  }

  FOR (i, 1, n) {
    FOR (j, 1, n) {
      cin >> a[i][j];
      d[i][j] = a[i][j] + p[j];
    }
    d[i][i] = 0;
  }

  FOR (k, 1, n) FOR (i, 1, n) FOR (j, 1, n) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

  FOR (i, 1, m) {
    cin >> flight[i].from >> flight[i].to >> flight[i].time;
  }

  FOR (i, 1, m) {
    FOR (j, 1, m) {
      if (flight[i].time + a[flight[i].from][flight[i].to] + p[flight[i].to] + d[flight[i].to][flight[j].from] <= flight[j].time) {
        g[i].push_back(j);
      }
    }
  }

  FOR (u, 1, m) {
    if (!matchX[u]) {
      s = u;
      found = false;
      dfs(u);
    }
  }

  int res = m;
  FOR (u, 1, m) if (matchX[u]) res--;
  cout << res << endl;
}

