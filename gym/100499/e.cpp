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

#define MAX 100111

struct Node {
  int left, right, v;
} a[MAX];

set<pair<int, int>> *s[MAX];

int res;

void remove(int u, set<pair<int, int>> *s) {
  if (u == 0) return;
  auto it = s->find(make_pair(a[u].v, u));
  if (it == s->end()) return;
  s->erase(it);
  remove(a[u].left, s);
  remove(a[u].right, s);
}

void dfs(int u) {
  int left = a[u].left, right = a[u].right, v = a[u].v;

  if (left) {
    dfs(left);

    while (!s[left]->empty()) {
      auto it = s[left]->end();
      it--;
      int t = it->second;
      if (a[t].v < v) break;
      remove(t, s[left]);
    }

    s[u] = s[left];
  } else {
    s[u] = new set<pair<int, int>>();
  }

  if (right) {
    dfs(right);

    while (!s[right]->empty()) {
      auto it = s[right]->begin();
      int t = it->second;
      if (v < a[t].v) break;
      remove(t, s[right]);
    }
    
    if (s[u]->size() < s[right]->size()) {
      for (auto it : *s[u]) {
        s[right]->insert(it);
      }
      s[u] = s[right];
    } else {
      for (auto it : *s[right]) {
        s[u]->insert(it);
      }
    }
  }

  s[u]->insert(make_pair(v, u));
  res = max(res, (int)s[u]->size());
}

int main() {
  int numt;
  cin >> numt;
  while (numt--) {
    int n;
    cin >> n;
    FOR (i, 1, n) {
      scanf("%d%d%d", &a[i].left, &a[i].right, &a[i].v);
      s[i] = NULL;
    }
    res = 0;
    dfs(1);
    cout << res << endl;
  }
}

