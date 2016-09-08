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

#define MAX 111

vector<int> a[MAX], place[MAX], weapon[MAX];
bool avail[MAX][MAX];

int used[MAX], s, matchX[MAX], matchY[MAX];
bool found;

void dfs(int u) {
  used[u] = s;

  REP (i, a[u].size()) {
    int v = a[u][i];

    if (!matchY[v]) found = true;
    else if (used[matchY[v]] != s) dfs(matchY[v]);

    if (found) {
      matchX[u] = v;
      matchY[v] = u;
      return;
    }
  }
}

int main() {
  int _;
  cin >> _;
  while (_--) {
    int nSoldier, nPlace, nWeapon;
    cin >> nSoldier >> nPlace >> nWeapon;

    FOR (i, 1, nSoldier) {
      place[i].clear();
      int m;
      cin >> m;
      REP (j, m) {
        int x;
        cin >> x;
        place[i].push_back(x);
      }
    }

    FOR (i, 1, nSoldier) {
      weapon[i].clear();
      int m;
      cin >> m;
      REP (j, m) {
        int x;
        cin >> x;
        weapon[i].push_back(x);
      }
    }

    FOR (i, 1, nPlace) FOR(j , 1, nWeapon) avail[i][j] = false;

    FOR (i, 1, nPlace) {
      int m;
      cin >> m;
      REP (j, m) {
        int x;
        cin >> x;
        avail[i][x] = true;
      }
    }

    FOR (i, 1, nSoldier) {
      a[i].clear();
      for (int j : place[i]) {
        for (int k : weapon[i]) {
          if (avail[j][k]) {
            a[i].push_back(j);
            break;
          }
        }
      }
    }

    FOR (i, 1, nSoldier) {
      matchX[i] = 0;
      used[i] = 0;
    }
    FOR (i, 1, nPlace) matchY[i] = 0;

    FOR (u, 1, nSoldier) {
      if (!matchX[u]) {
        s = u;
        found = false;
        dfs(u);
      }
    }

    int res = 0;
    FOR (u, 1, nSoldier) if (matchX[u]) res++;
    cout << res << endl;
  }
}

