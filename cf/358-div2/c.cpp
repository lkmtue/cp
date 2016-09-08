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

#define MAX 100111

int n;
vector<pair<int, ll> > a[MAX];
int w[MAX];

int sz[MAX];
ll f[MAX];

void calcSz(int u, int par) {
  sz[u] = 1;
  REP (i, a[u].size()) {
    int v = a[u][i].first;
    if (v != par) {
      calcSz(v, u);
      sz[u] += sz[v];
    }
  }
}

int res = 0;

void dfs(int u, int par, ll l) {
  if (par != 0) {
    f[u] = max(0LL, max(l, l + f[par]));
  } else {
    f[u] = 0;
  }

  if (f[u] > w[u]) {
    res += sz[u];
    return;
  }

  REP (i, a[u].size()) {
    int v = a[u][i].first;
    if (v != par) {
      dfs(v, u, a[u][i].second);
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  FOR (i, 1, n) cin >> w[i];
  FOR (i, 1, n - 1) {
    int j;
    ll l;

    cin >> j >> l;

    a[i + 1].push_back(make_pair(j, l));
    a[j].push_back(make_pair(i + 1, l));
  }

  calcSz(1, 0);

  dfs(1, 0, 0);

  cout << res;
}

