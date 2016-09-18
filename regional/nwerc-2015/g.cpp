#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <unordered_map>
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
int a[MAX], b[MAX], c[MAX], newV[MAX], posC[MAX];

unordered_map<int, int> tree[MAX];

void update(int x, int y) {
  while (x <= n) {
    int z = y;

    while (z <= n) {
      tree[x][z]++;
      z += z & (-z);
    }

    x += x & (-x);
  }
}

int get(int x, int y) {
  int res = 0;

  while (x) {
    int z = y;

    while (z) {
      res += tree[x][z];
      z -= z & (-z);
    }

    x -= x & (-x);
  }

  return res;
}

int main() {
  cin >> n;

  FOR (i, 1, n) {
    scanf("%d", &a[i]);
    newV[a[i]] = i;
  }


  FOR (i, 1, n) {
    scanf("%d", &b[i]);
    b[i] = newV[b[i]];
  }
  FOR (i, 1, n) {
    scanf("%d", &c[i]);
    c[i] = newV[c[i]];
    posC[c[i]] = i;
  }

  ll res = 0;

  FOR (i, 1, n) {
    int v = b[i];
    int j = posC[v];
    int temp = get(j, v);
    res += temp;
    update(j, v);
  }

  cout << res;
}

