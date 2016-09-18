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

int n;

int ask(int x1, int y1, int x2, int y2) {
  cout << "?" << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
  fflush(stdout);
  int res;
  cin >> res;
  return res;
}

int getTop(int top, int bot, int left, int right, int v) {
  int low = bot;
  int high = top;
  int res = 0;

  while (low <= high) {
    int mid = (low + high) / 2;
    if (ask(bot, left, mid, right) == v) {
      res = mid;
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  return res;
}

int getBot(int top, int bot, int left, int right, int v) {
  int low = bot;
  int high = top;
  int res = 0;
  while (low <= high) {
    int mid = (low + high) / 2;
    if (ask(mid, left, top, right) == v) {
      res = mid;
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return res;
}

int getLeft(int top, int bot, int left, int right, int v) {
  int low = left;
  int high = right;
  int res = 0;
  while (low <= high) {
    int mid = (low + high) / 2;
    if (ask(bot, mid, top, right) == v) {
      res = mid;
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return res;
}

int getRight(int top, int bot, int left, int right, int v) {
  int low = left;
  int high = right;
  int res = 0;
  while (low <= high) {
    int mid = (low + high) / 2;
    if (ask(bot, left, top, right) == v) {
      res = mid;
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  return res;
}

int getSepCol(int top, int bot, int left, int right) {
  int low = left;
  int high = right - 1;
  int res = -1;

  while (low <= high) {
    int mid = (low + high) / 2;
    int t = ask(bot, left, top, mid);
    if (t == 1) {
      res = t;
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  return res;
}

int getSepRow(int top, int bot, int left, int right) {
  int low = bot;
  int high = top - 1;
  int res = -1;

  while (low <= high) {
    int mid = (low + high) / 2;
    int t = ask(bot, left, mid, right);

    if (t == 0) {
      low = mid + 1;
    } else {
      res = t;
      high = mid - 1;
    }
  }
  return res;
}

void f(int bot, int left, int top, int right, int &x, int &y, int &z, int &t) {
  x = getBot(top, bot, left, right, 1);
  y = getLeft(top, bot, left, right, 1);
  z = getTop(top, bot, left, right, 1);
  t = getRight(top, bot, left, right, 1);
}

int x11, y11, x12, y12, x21, y21, x22, y22;

int main() {
  cin >> n;
  int top = getTop(n, 1, 1, n, 2);
  int bot = getBot(n, 1, 1, n, 2);
  int left = getLeft(n, 1, 1, n, 2);
  int right = getRight(n, 1, 1, n, 2);

  int midCol = getSepCol(top, bot, left, right);

  if (midCol != -1) {
    f(bot, left, top, midCol, x11, y11, x12, y12);
    f(bot, midCol, top, right, x21, y21, x22, y22);
  } else {
    int midRow = getSepRow(top, bot, left, right);
    f(bot, left, top, midCol, x11, y11, x12, y12);
    f(bot, midCol, top, right, x21, y21, x22, y22);
  }
  printf("%d %d %d %d %d %d %d %d\n", x11, y11, x12, y12, x21, y21, x22, y22);
  fflush(stdout);
}

