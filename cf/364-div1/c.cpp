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

int n, m, s, t; 

int best[MAX][MAX];

vector<pair<int, int> > a[MAX];

bool visited[MAX];
int par[MAX];

void dfs(int u) {
  visited[u] = true;

  REP (i, a[u].size()) {
    int v = a[u][i].first;

    if (!visited[v]) {
      par[v] = u;
      dfs(v);
    }
  }
}

int rmU, rmV;
int nEdge[MAX][MAX];
int cnt = 0;
bool containT[MAX];
int low[MAX], num[MAX], parent[MAX], nChild[MAX];

int res, nres, res1, res2, res3, res4;

void visit(int u) {
  num[u] = ++cnt;

  low[u] = n + 1;

  containT[u] = u == t;
  
  REP (i, a[u].size()) {
    int v = a[u][i].first;
    if (nEdge[u][v] == 0) continue;
    nEdge[v][u]--;
    if (parent[v] == 0) {
      parent[v] = u;
      visit(v);
      containT[u] = containT[u] || containT[v];
      low[u] = min(low[u], low[v]);
    } else {
      low[u] = min(low[u], num[v]);
    }
  }
}

void attempt() {
  cnt = 0;
  memset(parent, 0, sizeof(parent));

  FOR (u, 1, n) {
    REP (i, a[u].size()) {
      int v = a[u][i].first;
      nEdge[u][v] = 0;
    }
    REP (i, a[u].size()) {
      int v = a[u][i].first;
      nEdge[u][v]++;
    }
  }

  nEdge[rmU][rmV]--;
  nEdge[rmV][rmU]--;

  parent[s] = -1;
  memset(containT, false, sizeof(containT));
  visit(s);

  memset(nChild, 0, sizeof(nChild));
  FOR (v, 1, n) {
    if (parent[v] > 0) {
      nChild[parent[v]]++;
    }
  }

  if (parent[t] == 0) {
    if (res > best[rmU][rmV]) {
      res = best[rmU][rmV];
      nres = 1;
      res1 = rmU;
      res2 = rmV;
    }
  }

  FOR (v, 1, n) {
    int u = parent[v];
    if (u > 0 && low[v] >= num[v]) {
      if (containT[v]) {
        int temp = best[u][v] + best[rmU][rmV];
        if (temp < res) {
          res = temp;
          nres = 2;
          res1 = u;
          res2 = v;
          res3 = rmU;
          res4 = rmV;
        }
      }
    }
  }
}

map<pair<pair<int, int>, int>, int> id;

int main() {
  cin >> n >> m >> s >> t;

  FOR (i, 1, n) FOR (j, 1, n) best[i][j] = 1000111000;

  FOR (i, 1, m) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    a[u].push_back(make_pair(v, w));
    a[v].push_back(make_pair(u, w));
    best[u][v] = min(best[u][v], w);
    best[v][u] = min(best[v][u], w);
    id[make_pair(make_pair(u, v), w)] = i;
    id[make_pair(make_pair(v, u), w)] = i;
  }

  FOR (i, 1, n) if (!visited[i]) dfs(i);

  res = 2000111000;

  for (rmV = 1; rmV <= n; rmV++) {
    rmU = par[rmV];
    if (rmU == 0) continue;

    attempt();
  }

  if (res == 2000111000) {
    cout << -1 << endl;
    return 0;
  }

  cout << res << endl;
  cout << nres << endl;
  cout << id[make_pair(make_pair(res1, res2), best[res1][res2])];
  if (nres == 2) {
    cout << " " << id[make_pair(make_pair(res3, res4), best[res3][res4])];
  }
  cout << endl;
}

