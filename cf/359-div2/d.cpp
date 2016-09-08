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

#define MAX 300111
int sz[MAX], f[MAX], par[MAX], maxSz[MAX];
vector<int> a[MAX];

void dfs(int u) {
  sz[u] = 1;
  maxSz[u] = -1;

  REP (i, a[u].size()) {
    int v = a[u][i];
    dfs(v);
    sz[u] += sz[v];
    maxSz[u] = max(maxSz[u], sz[v]);
  }

  if (a[u].size() == 0) {
    f[u] = u;
    return;
  }

  REP (i, a[u].size()) {
    int v = a[u][i];
    int x = f[v];
    while (x != u) {
      int t = sz[u] - sz[x];
      if (max(maxSz[x], t) * 2 <= sz[u]) {
        f[u] = x;
        return;
      }
      x = par[x];
    }
  }
  f[u] = u;
}

int main() {
  int n, q;
  scanf("%d%d", &n, &q);

  FOR (j, 2, n) {
    int i;
    scanf("%d", &i);
    par[j] = i;
    a[i].push_back(j);
  }

  dfs(1);

  FOR (i, 1, q) {
    int u;
    scanf("%d", &u);
    printf("%d\n", f[u]);
  }
}

