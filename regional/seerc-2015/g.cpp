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

int n;
vector<int> a[MAX];
int c[MAX];

int main() {
  ios::sync_with_stdio(false);
  scanf("%d", &n);

  REP (i, n) {
    int cnt;
    scanf("%d:", &cnt);
    REP (_, cnt) {
      int x;
      scanf("%d", &x);
      a[i].push_back(x);
    }
  }

  while (1) {
    bool found = false;
    REP (i, n) {
      int cnt = 0;
      REP (j, a[i].size()) {
        int k = a[i][j];
        if (c[i] == c[k]) {
          cnt++;
        }
      }
      if (cnt > a[i].size() / 2) {
        found = true;
        c[i] = 1 - c[i];
        break;
      }
    }
    if (!found) break;
  }

  cout << n << endl;
  REP (i, n) {
    cout << c[i] << " " << a[i].size() << ": ";
    REP (j, a[i].size()) {
      cout << a[i][j];
      if (j + 1 < a[i].size()) {
        cout << " ";
      }
    }
    cout << endl;
  }
}

