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

int a[MAX], b[MAX];

struct Element {
  Element(ll a, ll b) : a(a), b(b), sumA(0), sumB(0) {}
  ll a, b;
  ll sumA, sumB;
};

vector<Element> sorted[MAX * 10];

void merge(vector<Element> &a, vector<Element> &b, vector<Element> &c) {
  int i = 0, j = 0, k = 0;
  int n = b.size(), m = c.size();

  while (i < n || j < m) {
    if (i == n) {
      a.push_back(c[j++]);
    } else if (j == m) {
      a.push_back(b[i++]);
    } else if (b[i].b == 0) {
      a.push_back(b[i++]);
    } else if (c[j].b == 0) {
      a.push_back(c[j++]);
    } else if (b[i].a * c[j]. b >= c[j].a * b[i].b) {
      a.push_back(b[i++]);
    } else {
      a.push_back(c[j++]);
    }

    if (k == 0) {
      a[0].sumA = a[0].a;
      a[0].sumB = a[0].b;
    } else {
      a[k].sumA = a[k - 1].sumA + a[k].a;
      a[k].sumB = a[k - 1].sumB + a[k].b;
    }

    k++;
  }
}

void init(int l, int r, int p) {
  if (l == r) {
    if (a[l] != 0) {
      sorted[p].push_back(Element(a[l], b[l]));
    }
    return;
  }
  init(l, (l + r) / 2, p * 2);
  init((l + r) / 2 + 1, r, p * 2 + 1);
  merge(sorted[p], sorted[p * 2], sorted[p * 2 + 1]);
}

int x, y, c, d;
ll sumA, sumB;

void visit(int l, int r, int p) {
  if (x <= l && r <= y) {
    vector<Element> &a = sorted[p];
    
    int i = -1;
    int low = 0;
    int high = ((int)a.size()) - 1;

    while (low <= high) {
      int mid = (low + high) / 2;

      if (a[mid].b == 0 || a[mid].a * c > d * a[mid].b) {
        i = mid;
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }

    if (i != -1) {
      sumA += a[i].sumA;
      sumB += a[i].sumB;
    }

    return;
  }

  if (y < l || r < x) return;

  visit(l, (l + r) / 2, p * 2);
  visit((l + r) / 2 + 1, r, p * 2 + 1);
}

int main() {
  ios::sync_with_stdio(false);
  int n, nq;

  scanf("%d", &n);
  FOR (i, 1, n) scanf("%d", &a[i]);
  FOR (i, 1, n) scanf("%d", &b[i]);

  init(1, n, 1);

  scanf("%d", &nq);
  while (nq--) {
    scanf("%d%d%d%d", &x, &y, &c, &d);

    ll res = 0;

    if (c != 0) {
      sumA = 0;
      sumB = 0;

      visit(1, n, 1);

      res = sumA * c - sumB * d;
    }

    cout << res << endl;
    fflush(stdout);
  }
}

