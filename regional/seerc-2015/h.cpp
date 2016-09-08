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

#define MAX 100111

int k, n, t;

set<int> start[MAX], finish[MAX];

int lastRelease[MAX];
bool current[MAX];

int main() {
  ios::sync_with_stdio(false);
  cin >> k >> n >> t;

  REP (i, t) {
    int p, s, f;
    cin >> p >> s >> f;

    start[s].insert(p);
    finish[f].insert(p);
  }

  FOR (i, 1, k) {
    lastRelease[i] = 1;
  }

  int last = 0;
  int res = 0;
  FOR (i, 1, n) {
    for (set<int>::iterator it = finish[i].begin(); it != finish[i].end(); it++) {
      current[*it] = false;
      lastRelease[*it] = i;
    }
    for (set<int>::iterator it = start[i].begin(); it != start[i].end(); it++) {
      current[*it] = true;
    }
    int cnt = 0;
    if (i < n) {
      int x = n + 1;
      FOR (j, 1, k) {
        if (!current[j]) {
          x = min(x, lastRelease[j]);
        } else {
          cnt++;
        }
      }
      if (x <= n) {
        int temp = i + 1 - x;
        res -= temp;
      }
    }

    if (i == n || cnt == k) {
      res += (i - last) * (i - last - 1) / 2;
      last = i;
    }
  }

  cout << res;
}

