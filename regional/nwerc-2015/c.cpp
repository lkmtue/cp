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
#define EPS 1e-6

inline int cmp(double a, double b) {
    return (a < b - EPS) ? -1 : ((a > b + EPS) ? 1 : 0);
}

struct Point {
    double x, y;
    Point(double x = 0.0, double y = 0.0) : x(x), y(y) {}

    Point operator + (const Point& a) const { return Point(x+a.x, y+a.y); }
    Point operator - (const Point& a) const { return Point(x-a.x, y-a.y); }
    Point operator * (double k) const { return Point(x*k, y*k); }
    Point operator / (double k) const { return Point(x/k, y/k); }

    double operator * (const Point& a) const { return x*a.x + y*a.y; } // dot product
    double operator % (const Point& a) const { return x*a.y - y*a.x; } // cross product

    int cmp(Point q) const { if (int t = ::cmp(x,q.x)) return t; return ::cmp(y,q.y); }

    #define Comp(x) bool operator x (Point q) const { return cmp(q) x 0; }
    Comp(>) Comp(<) Comp(==) Comp(>=) Comp(<=) Comp(!=)
    #undef Comp

    Point conj() { return Point(x, -y); }
    double norm() { return x*x + y*y; }

    // Note: There are 2 ways for implementing len():
    // 1. sqrt(norm()) --> fast, but inaccurate (produce some values that are of order X^2)
    // 2. hypot(x, y) --> slow, but much more accurate
    double len() { return sqrt(norm()); }

    Point rotate(double alpha) {
        double cosa = cos(alpha), sina = sin(alpha);
        return Point(x * cosa - y * sina, x * sina + y * cosa);
    }
};

struct Line {
    double a, b, c;
    Point A, B; // Added for polygon intersect line. Do not rely on assumption that these are valid

    Line(double a, double b, double c) : a(a), b(b), c(c) {}

    Line(Point A, Point B) : A(A), B(B) {
        a = B.y - A.y;
        b = A.x - B.x;
        c = - (a * A.x + b * A.y);
    }
    Line(Point P, double m) {
        a = -m; b = 1;
        c = -((a * P.x) + (b * P.y));
    }
    double f(Point A) {
        return a*A.x + b*A.y + c;
    }
};

bool areParallel(Line l1, Line l2) {
    return cmp(l1.a*l2.b, l1.b*l2.a) == 0;
}

bool areSame(Line l1, Line l2) {
    return areParallel(l1 ,l2) && cmp(l1.c*l2.a, l2.c*l1.a) == 0
                && cmp(l1.c*l2.b, l1.b*l2.c) == 0;
}

bool areIntersect(Line l1, Line l2, Point &p) {
    if (areParallel(l1, l2)) return false;
    double dx = l1.b*l2.c - l2.b*l1.c;
    double dy = l1.c*l2.a - l2.c*l1.a;
    double d  = l1.a*l2.b - l2.a*l1.b;
    p = Point(dx/d, dy/d);
    return true;
}


int w, p, xw[1111], yw[1111], x[1111], y[1111], st[1111];
vector<int> adj[1111];
vector<int> m[2];
int vst[1111];
bool flag;
int cnt[1111];

bool inside(Point p, Line ab) {
  return cmp((p - ab.A).len() + (p - ab.B).len(), (ab.A - ab.B).len()) == 0;
}

bool cross(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
  Point a(x1, y1);
  Point b(x2, y2);
  Point c(x3, y3);
  Point d(x4, y4);

  if (a == c || a == d || b == c || b == d) return true;

  Line ab(a, b);
  Line cd(c, d);

  Point p;

  if (!areIntersect(ab, cd, p)) {
    return false;
  }

  return inside(p, ab) && inside(p, cd);
}

int ww[1111];

void solve(int x) {
  for (int nex: adj[x]) {
    if (!~vst[nex]) {
      vst[nex] = 1 - vst[x];
      m[vst[nex]].push_back(nex);
      ww[st[nex]] = vst[nex];
      solve(nex);
    }
    else if(vst[nex] == vst[x]) {
      flag = true;
      return;
    }
  }
}


int main() {
  cin >> w >> p;
  FOR (i, 1, w) cin >> xw[i] >> yw[i];
  FOR (i, 1, p) cin >> st[i] >> x[i] >> y[i];
  FOR (i, 1, p) FOR (j, i + 1, p) if (st[i] != st[j]) {
    if (cross(xw[st[i]], yw[st[i]], x[i], y[i], xw[st[j]], yw[st[j]], x[j], y[j]))
      adj[i].push_back(j);
      adj[j].push_back(i);
  }
  memset(vst, -1, sizeof(vst));
  flag = false;
  FOR (i, 1, p) if (!~vst[i]) {
    vst[i] = 1 - ww[st[i]];
    m[vst[i]].push_back(i);
    solve(i);
  }
  if (flag) {
    cout << "impossible";
    return 0;
  }
  memset(cnt, 0, sizeof(cnt));
  flag = false;
  for (int i: m[0]) {
    cnt[st[i]]++;
    if (cnt[st[i]] > 1) flag = true;
  }
  if (!flag) {
    cout << "possible";
    return 0;
  }
  memset(cnt, 0, sizeof(cnt));
  flag = false;
  for (int i: m[1]) {
    cnt[st[i]]++;
    if (cnt[st[i]] > 1) flag = true;
  }
  if (!flag) {
    cout << "possible";
    return 0;
  }
  cout << "impossible";
}

