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

int n;
int a[MAX];
pii tree[MAX * 5];
ll f[MAX];

pii query(int x, int y, int l, int r, int p) {
  if (y < l || r < x) {
    return make_pair(-1, -1);
  }
  if (x <= l && r <= y) {
    return tree[p];
  }
  return max(query(x, y, l, (l + r) / 2, p * 2), query(x, y, (l + r) / 2 + 1, r, p * 2 + 1));
}

void init(int l, int r, int p) {
  if (l == r) {
    tree[p] = make_pair(a[l], l);
    return;
  }
  init(l, (l + r) / 2, p * 2);
  init((l + r) / 2 + 1, r, p * 2 + 1);
  tree[p] = max(tree[p * 2], tree[p * 2 + 1]);
}

int main() {
  int n;
  cin >> n;
  FOR (i, 1, n - 1) {
    cin >> a[i];
  }

  init(1, n, 1);
  
  ll res = 0;
  FORD (i, n - 1, 1) {
    pii p = query(i + 1, a[i], 1, n ,1);
    int j = p.second;
    f[i] = j - i + f[j] + (n - a[i]);
    res += f[i];
  }
  cout << res << endl;
}

