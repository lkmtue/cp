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

#define MAX 400111
#define MOD 1000000007

vector<pair<int, int>> a[MAX];
int height[MAX];
bool deleted[MAX];

int b[MAX], c[MAX];
int g = 0;
int cnt = 0;

ll p[MAX];

void dfs(int u) {
  REP (i, a[u].size()) {
    int v = a[u][i].first;
    int id = a[u][i].second;
    if (deleted[id]) {
      continue;
    }
    deleted[id] = true;
    c[g]++;
    if (height[v] != -1) {
      b[g] = height[u] - height[v] + 1;
    } else {
      height[v] = height[u] + 1;
      dfs(v);
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;

  int id = 0;

  FOR (i, 1, n) {
    int j;
    cin >> j;
    id++;
    a[i].push_back(make_pair(j, id));
    a[j].push_back(make_pair(i, id));
  }

  memset(height, -1, sizeof(height));

  cnt = n;

  FOR (i, 1, n) {
    if (height[i] == -1) {
      height[i] = 0;
      g++;
      dfs(i);
    }
  }

  p[0] = 1;
  FOR (i, 1, n) p[i] = (p[i- 1] * 2) % MOD;

  ll res = 1;
  FOR (i, 1, g) {
    res = (res * p[c[i] - b[i]]) % MOD;
    res = (res * (p[b[i]] - 2 + MOD)) % MOD;
  }
  cout << res << endl;
}

