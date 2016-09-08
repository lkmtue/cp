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

vector<int> a, b;
vector<int> adj[MAX];

int gcd(int x, int y) {
  if (y == 0) return x;
  return gcd(y, x % y);
}

int s;
bool found;
int used[MAX];
int matchx[MAX];
int matchy[MAX];

void dfs(int u) {
  used[u] = s;
  REP (i, adj[u].size()) {
    int v = adj[u][i];
    if (matchy[v] == -1) found = true;
    else if (used[matchy[v]] != s) dfs(matchy[v]);
    if (found) {
      matchx[u] = v;
      matchy[v] = u;
      return;
    }
  }
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    map<int, bool> appear;

    a.clear();
    b.clear();

    REP (i, n) {
      int x;
      cin >> x;

      if (appear[x]) continue;
      appear[x] = true;

      if (x % 2) {
        b.push_back(x);
      } else {
        a.push_back(x);
      }
    }

    REP (i, a.size()) {
      adj[i].clear();

      REP (j, b.size()) {
        if (gcd(a[i], b[j]) > 1) {
          adj[i].push_back(j);
        }
      }
    }

    memset(used, -1, sizeof(used));
    memset(matchx, -1, sizeof(matchx));
    memset(matchy, -1, sizeof(matchy));

    REP (i, a.size()) {
      if (matchx[i] == -1) {
        s = i;
        found = false;
        dfs(i);
      }
    }

    int match = 0;
    REP (i, a.size()) {
      if (matchx[i] != -1) {
        match++;
      }
    }

    int res = a.size() + b.size() - match;
    cout << res << endl;
  }
}

