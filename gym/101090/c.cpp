#include <algorithm>
#include <cmath>
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

int V;
int n, m;
vector<int> G[MAX];

struct UndirectedDfs {
    vector<int> low, num, parent;
    vector<bool> articulation;
    int counter, root, children;

    vector< pair<int,int> > bridges;
    vector<int> cuts;

    UndirectedDfs() : low(V, 0), num(V, -1), parent(V, 0), articulation(V, false),
            counter(0), children(0) {
        for(int i = 0; i < V; ++i) if (num[i] == -1) {
            root = i; children = 0;
            dfs(i);
            articulation[root] = (children > 1);
        }
        for(int i = 0; i < V; ++i)
            if (articulation[i]) cuts.push_back(i);
    }
private:
    void dfs(int u) {
        low[u] = num[u] = counter++;
        for(int j = 0; j < G[u].size(); ++j) {
            int v = G[u][j];
            if (num[v] == -1) {
                parent[v] = u;
                if (u == root) children++;
                dfs(v);
                if (low[v] >= num[u])
                    articulation[u] = true;
                if (low[v] > num[u]) bridges.push_back(make_pair(u, v));
                low[u] = min(low[u], low[v]);
            } else if (v != parent[u])
                low[u] = min(low[u], num[v]);
        }
    }
};

set<int> a[MAX];
bool visited[MAX];
bool isBridge[MAX][MAX];
int g[MAX], cnt;
vector<int> inG[MAX];

void dfs(int u) {
  g[u] = cnt;
  inG[cnt].push_back(u);

  for (auto v : G[u]) {
    if (!g[v] && !isBridge[u][v]) {
      dfs(v);
    }
  }
}

vector<int> list;

void visit(int u) {
  visited[u] = true;
  bool leaf = true;
  for (auto v : a[u]) {
    if (!visited[v]) {
      visit(v);
      leaf = false;
    }
  }
  if (leaf) {
    list.push_back(u);
  }
}

bool exist[MAX][MAX];

void pr(int u, int v) {
  for (auto x : inG[u])
    for (auto y : inG[v]) {
      if (!exist[x][y]) {
        cout << x + 1 << " " << y + 1 << endl;
        return;
      }
    }
}

int main() {
  cin >> n >> m;
  FOR (i, 1, m) {
    int u, v;
    cin >> u >> v;
    --u; --v;
    G[u].push_back(v);
    G[v].push_back(u);
    exist[u][v] = true;
    exist[v][u] = true;
  }

  V = n;
  UndirectedDfs tree;
  for (auto p : tree.bridges) {
    isBridge[p.first][p.second] = true;
    isBridge[p.second][p.first] = true;
  }

  REP (i, n) if (!g[i]) {
    ++cnt;
    dfs(i);
  }

  REP (i, n) {
    for (auto j : G[i]) {
      if (g[i] != g[j]) {
        a[g[i]].insert(g[j]);
        a[g[j]].insert(g[i]);
      }
    }
  }

  if (cnt == 2) {
    if (n == 2 && exist[0][1]) {
      cout << -1 << endl;
    } else {
      cout << 1 << endl;
      pr(1, 2);
    }
    return 0;
  } else {
    FOR (i, 1, cnt) {
      if (a[i].size() > 1) {
        visit(i);
        break;
      }
    }
  }

  int res = (list.size() + 1) / 2;
  cout << res << endl;

  REP (i, res) {
    int j = (i + list.size() / 2) % list.size();
    pr(list[i], list[j]);
  }
}

