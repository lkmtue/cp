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

int n;
vector<int> b[MAX];
int p[MAX];
int res[MAX];
int root;
bool visited[MAX];
map<int, int> cnt[MAX];

void visit(int u) {
  visited[u] = true;

  REP (i, b[u].size()) {
    int v = b[u][i];

    if (cnt[u][v] == 0) {
      continue;
    }

    cnt[v][u]--;

    if (visited[v]) {
      if (root != 0) {
        res[u] = root;
      } else {
        root = u;
        res[u] = u;
      }
    } else {
      visit(v);
    }
  }
}

void add(int u, int v) {
  b[u].push_back(v);
  cnt[u][v]++;
}

int main() {
  while (cin >> n) {
    memset(visited, false, sizeof(visited));
    memset(res, 0, sizeof(res));
    root = 0;

    FOR (i, 1, n) {
      scanf("%d", &p[i]);

      if (i == p[i]) {
        root = i;
        continue;
      }

      add(i, p[i]);
      add(p[i], i);
      res[i] = p[i];
    }

    FOR (i, 1, n) {
      if (!visited[i]) {
        visit(i);
      }
    }

    FOR (i, 1, n) {
      if (res[i] == 0) {
        res[i] = root;
      }
    }

    int change = 0;
    FOR (i, 1, n) if (res[i] != p[i]) change++;
    cout << change << endl;

    FOR (i, 1, n) printf("%d ", res[i]);
    cout << endl;

    FOR (i, 1, n) {
      b[i].clear();
      cnt[i].clear();
    }
  }
}

