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
#define MAXM 10111

const ll oo = 1e18;

vector<pair<int, ll>> a[MAX];
int id[MAX][MAX];
vector<pair<pii, ll>> edges;

ll d[MAX][2];
pii trace[MAX][2];

ll res[MAXM];

int n, m, s, t;
ll l;

void no() {
  cout << "NO" << endl;
  exit(0);
}

vector<int> doTrace(int crossed) {
  vector<int> res;
  int u = t, c = crossed;

  while (u != s) {
    res.push_back(u);
    int uu = trace[u][c].first;
    int cc = trace[u][c].second;
    u = uu;
    c = cc;
  }

  res.push_back(u);
  return res;
}

int main() {
  cin >> n >> m >> l >> s >> t;
  REP (i, m) {
    int u, v;
    ll w;
    cin >> u >> v >> w;

    a[u].push_back(make_pair(v, w));
    a[v].push_back(make_pair(u, w));
    id[u][v] = i;
    id[v][u] = i;

    edges.push_back(make_pair(make_pair(u, v), w));
  }

  priority_queue<pair<ll, pii>> q;

  REP (u, n) {
    d[u][0] = oo;
    d[u][1] = oo;
  }

  d[s][0] = 0;
  q.push(make_pair(0, make_pair(s, 0)));

  while (!q.empty()) {
    auto p = q.top();
    q.pop();

    ll du = -p.first;
    int u = p.second.first;
    int crossed = p.second.second;


    if (d[u][crossed] != du) continue;

    for (auto edge : a[u]) {
      int v = edge.first;
      ll w = edge.second;

      ll dv = 0;
      int newCrossed = crossed;

      if (w == 0) {
        dv = du + 1;
        newCrossed = 1;
      } else {
        dv = du + w;
      }

      if (dv < d[v][newCrossed]) {
        d[v][newCrossed] = dv;
        trace[v][newCrossed] = make_pair(u, crossed);
        q.push(make_pair(-dv, make_pair(v, newCrossed)));
      }
    }
  }

  if (d[t][0] < l) no();
  if (d[t][0] > l && d[t][1] > l) no();

  vector<int> path;
  ll remain = l;

  if (d[t][0] == l) path = doTrace(0);
  else {
    path = doTrace(1);
    remain -= d[t][1];
  }

  reverse(path.begin(), path.end());

  vector<pii> zeros;

  REP (i, (int)path.size() - 1) {
    int u = path[i];
    int v = path[i + 1];
    ll w = edges[id[u][v]].second;

    if (w == 0) zeros.push_back(make_pair(u, v));
  }

  remain += zeros.size();

  REP (i, zeros.size()) {
    int u = zeros[i].first, v = zeros[i].second;
    if (i + 1 == zeros.size()) {
      res[id[u][v]] = remain;
    } else {
      res[id[u][v]] = 1;
      remain--;
    }
  }

  cout << "YES" << endl;

  for (auto e : edges) {
    int u = e.first.first, v = e.first.second;
    ll w = e.second;
    if (w == 0) {
      w = res[id[u][v]];
      if (w == 0) {
        w = oo;
      }
    }
    cout << u << " " << v << " " << w << endl;
  }
}

