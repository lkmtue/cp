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

int n, m;

vector<int> a[MAX];
int b[MAX], par[MAX];
bool choose[MAX];

void dfs(int u) {
  REP (i, a[u].size()) {
    int v = a[u][i];
    dfs(v);
  }
  if (choose[u]) {
    cout << u << endl;
  }
}

int main() {
  ios::sync_with_stdio(false);

  cin >> n >> m;

  int cnt = 0;

  FOR (i, 1, m) {
    int u, v;
    cin >> v >> u;

    par[u] = v;

    a[v].push_back(u);

  }

  FOR (i, 1, n) {
    cin >> b[i];
    if (!choose[b[i]]) {
      cnt++;
    }

    choose[b[i]] = true;
  }

  FOR (i, 1, n) {
    if ((par[i] == 0 && b[i] == i) || (par[i] != 0 && (b[i] == i || b[i] == b[par[i]]))) {
      continue;
    }

    cout << -1 << endl;
    return 0;
  }

  cout << cnt << endl;

  FOR (i, 1, n) {
    if (par[i] == 0) {
      dfs(i);
    }
  }
}

