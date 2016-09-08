#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAX 100111
#define oo 1000111000

int n, m, s, t;

vector<int> a[MAX], revA[MAX];

int trace[MAX];

vector<int> path, revPath, id, revId;
int d[MAX], revD[MAX];

int delta[MAX];

void tracePath() {
  int v = t;
  while (v != -1) {
    revPath.push_back(v);
    v = trace[v];
  }
  path = revPath;
  reverse(path.begin(), path.end());
}

void findOnePath() {
  queue<int> q;

  q.push(s);
  trace[s] = -1;

  while (!q.empty()) {
    int u = q.front();
    q.pop();

    for (int i = 0; i < a[u].size(); i++) {
      int v = a[u][i];
      if (!trace[v]) {
        trace[v] = u;
        q.push(v);
        if (v == t) {
          tracePath();
          return;
        }
      }
    }
  }
}

void initId() {
  int cnt = 0;
  id.resize(n + 1);
  for (int i = 0; i < path.size(); i++) {
    id[path[i]] = cnt++;
  }

  cnt = 0;
  revId.resize(n + 1);
  for (int i = 0; i < revPath.size(); i++) {
    revId[revPath[i]] = cnt++;
  }
}

void ijk(int s, vector<int> a[], vector<int> &id, int d[]) {
  priority_queue<pair<int, int> > q;

  for (int i = 1; i <= n; i++) {
    d[i] = oo;
  }

  q.push(make_pair(0, s));
  d[s] = 0;

  while (!q.empty()) {
    pair<int, int> p = q.top();
    q.pop();

    if (p.first != -d[p.second]) continue;

    int u = p.second;

    for (int i = 0; i < a[u].size(); i++) {
      int v = a[u][i];
      int l = max(d[u], id[v]);

      if (d[v] > l) {
        d[v] = l;
        q.push(make_pair(-l, v));
      }
    }
  }
}

void solve() {
  int l = path.size();

  for (int i = 1; i <= n; i++) {
    if (id[i] == 0 && i != s && i != t && d[i] != oo && revD[i] != oo) {
      int x = d[i];
      int y = l - 1 - revD[i];

      if (x < y) {
        // cout << i << " " << x << " " << y << " " << path[x] << " " << path[y] << endl;

        delta[x]++;
        delta[y - 1]--;
      }
    }
  }

  vector<int> result;
  int current = 0;
  for (int i = 0; i < l; i++) {
    if (current == 0 && i != 0 && i != l - 1) {
      result.push_back(path[i]);
    }
    current += delta[i];
  }

  sort(result.begin(), result.end());
  cout << result.size() << endl;
  for (int i = 0; i < result.size(); i++) {
    cout << result[i] << ' ';
  }
}

int main() {
  ios::sync_with_stdio(false);
  freopen("assassination.in", "r", stdin);
  cin >> n >> m >> s >> t;

  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    if (y == s || x == t) {
      continue;
    }
    a[x].push_back(y);
    revA[y].push_back(x);
  }

  findOnePath();
  // for (int i = 0; i < path.size(); i++) {
  //   cout << path[i] << " ";
  // }
  // cout << endl;

  initId();

  ijk(s, a, id, d);
  ijk(t, revA, revId, revD);

  solve();
}
