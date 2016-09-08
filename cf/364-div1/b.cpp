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

#define MAX 200111

int n, k;
int list[MAX];
bool b[MAX];
vector<int> a[MAX];
int f[MAX];
ll res;

void dfs(int u, int p) {
  f[u] = b[u] ? 1 : 0;
  REP (i, a[u].size()) {
    int v = a[u][i];
    if (v != p) {
      dfs(v, u);
      f[u] += f[v];
    }
  }

  res += min(f[u], 2 * k - f[u]);
}

int main() {
  cin >> n >> k;
  FOR (i, 1, 2 * k) {
    scanf("%d", &list[i]);
    b[list[i]] = true;
  }
  FOR (i, 1, n - 1) {
    int u, v;
    scanf("%d%d", &u, &v);
    a[u].push_back(v);
    a[v].push_back(u);
  }
  dfs(1, -1);
  cout << res << endl;
}

