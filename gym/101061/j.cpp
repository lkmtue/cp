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

int n, m;
int a[MAX];

struct Node {
  ll sum, wait;
} tree[MAX * 10];

void init(int l, int r, int p) {
  if (l == r) {
    tree[p].sum = a[l];
    tree[p].wait = 0;
    return;
  }

  init(l, (l + r) / 2, p * 2);
  init((l + r) / 2 + 1, r, p * 2 + 1);
  tree[p].sum = tree[p * 2].sum + tree[p * 2 + 1].sum;
  tree[p].wait = 0;
}

void lazyUpdate(int p) {
  int pp = p * 2;

  ll w = tree[p].wait;

  ll d = min(tree[pp].sum, w);

  tree[pp].sum -= d;
  tree[pp].wait += d;

  if (d < w) {
    d = w - d;
    tree[pp + 1].sum -= d;
    tree[pp + 1].wait += d;
  }

  tree[p].wait = 0;
}

ll update(int l, int r, int p, int x, ll v) {
  if (r < x || v == 0) {
    return 0;
  }

  lazyUpdate(p);

  if (l < x) {
    ll dl = update(l, (l + r) / 2, p * 2, x, v);
    ll dr = update((l + r) / 2 + 1, r, p * 2 + 1, x , v - dl);
    
    tree[p].sum = tree[p * 2].sum + tree[p * 2 + 1].sum;

    return dl + dr;
  } else {
    ll d = min(tree[p].sum, v);
    tree[p].sum -= d;
    tree[p].wait += d;
    return d;
  }
}

ll query(int l, int r, int p, int x) {
  if (x < l || r < x) {
    return -1;
  }
  if (l == r) {
    return tree[p].sum;
  }
  lazyUpdate(p);
  return max(query(l, (l + r) / 2, p * 2, x), query((l + r) / 2 + 1, r, p * 2 + 1, x));
}

int main() {
  int _;
  cin >> _;

  while (_--) {
    cin >> n >> m;
    FOR (i, 1, n) scanf("%d", &a[i]);

    init(1, n, 1);

    ll totalWaste = 0;

    FOR (i, 1, m) {
      int x, v;
      scanf("%d%d", &x, &v);
      ll used = update(1, n, 1, x, v);
      ll waste = v - used;
      totalWaste += waste;
    }

    cout << totalWaste << endl;
    FOR (i, 1, n) {
      printf("%d", a[i] - int(query(1, n, 1, i)));
      if (i < n) printf(" ");
    }
    cout << endl;
  }
}

