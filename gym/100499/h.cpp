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

#define MAX 22
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

    void print() {
      cout << x << " " << y << endl;
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

    void print() {
      cout << A.x << " " << A.y << " " << B.x << " " << B.y << endl;
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

struct Rect {
  Point lowerLeft, upperRight, upperLeft, lowerRight;
  vector<Point> corners;
} rect[MAX], bound;

struct Tri {
  Tri(Point a, Point b, Point c): a(a), b(b), c(c) {}
  Point a, b, c;

  double area() {
    return abs((b - a) % (c - a)) / 2;
  }

  Point center() {
    return Point((a.x + b.x + c.x) / 3.0, (a.y + b.y + c.y) / 3.0);
  }

  void print() {
    cout << a.x << " " << a.y << " " << b.x << " " << b.y << " " << c.x << " " << c.y << endl;
  }
};


bool cutSeg(Line l, Line seg, Point &p) {
  if (areIntersect(seg, l, p)) {
    double d = (seg.A - seg.B).len();
    double d1 = (seg.A - p).len();
    double d2 = (seg.B - p).len();

    if (cmp(d, d1 + d2) == 0) {
      return true;
    }

    return false;
  }
  return false;
}

void processLineTri(Line &l, Tri &tri, vector<Tri> &result) {
  Point &a = tri.a;
  Point &b = tri.b;
  Point &c = tri.c;

  Line ab(a, b);
  Line bc(b, c);
  Line ca(c, a);

  if (areSame(l, ab) || areSame(l, bc) || areSame(l, ca)) {
    result.push_back(tri);
    return;
  }

  Point u, v;
  if (cmp(l.f(a), 0) == 0 && cutSeg(l, bc, u)) {
    result.push_back(Tri(a, b, u));
    result.push_back(Tri(a, c, u));
  } else if (cmp(l.f(b), 0) == 0 && cutSeg(l, ca, u)) {
    result.push_back(Tri(a, b, u));
    result.push_back(Tri(b, c, u));
  } else if (cmp(l.f(c), 0) == 0 && cutSeg(l, ab, u)) {
    result.push_back(Tri(a, c, u));
    result.push_back(Tri(b, c, u));
  } else if (cutSeg(l, ab, u) && cutSeg(l, bc, v)) {
    result.push_back(Tri(b, u, v));
    result.push_back(Tri(c, u, v));
    result.push_back(Tri(a, u, c));
  } else if (cutSeg(l, ab, u) && cutSeg(l, ca, v)) {
    result.push_back(Tri(a, u, v));
    result.push_back(Tri(c, u, v));
    result.push_back(Tri(b, u, c));
  } else if (cutSeg(l, bc, u) && cutSeg(l, ca, v)) {
    result.push_back(Tri(c, u, v));
    result.push_back(Tri(b, u, v));
    result.push_back(Tri(a, b, v));
  }
}

void processLine(Line &l, vector<Tri> &tri) {
  vector<Tri> newTri;

  int i = 0;
  for (auto &triangle : tri) {
    processLineTri(l, triangle, newTri);

    if (i == 1) {
      for (auto t : newTri) {
        t.print();
      }
      while (1);
    }
    i++;
  }

  tri = newTri;
}

int n;

bool segCutSeg(Line a, Line b, Point &p) {
  return cutSeg(a, b, p) && cutSeg(b, a, p);
}

bool trackable(Point &u, Point &v) {
  Line uv(u, v);

  FOR (i, 1, n) {
    Rect &rec = rect[i];

    Point p;

    REP (j, 4) {
      Line edge(rec.corners[j], rec.corners[(j + 1) % 4]);

      if (segCutSeg(uv, edge, p)) {
        return false;
      }
    }
  }

  return true;
}

double solve(Point cctv) {
  vector<Tri> tri;

  tri.push_back(Tri(bound.lowerLeft, bound.upperLeft, bound.upperRight));
  tri.push_back(Tri(bound.lowerLeft, bound.lowerRight, bound.upperRight));

  // Init tri.
  FOR (i, 1, n) {
    for (auto &boxCorner : rect[i].corners) {
      Line l(cctv, boxCorner);
      processLine(l, tri);
    }
  }

  BUG("HERE");

  for (auto &t : tri) {
    t.print();
  }

  while (1);

  // Calc area.
  double res = 0;
  for (auto &triangle : tri) {
    Point center = triangle.center();
    if (trackable(cctv, center)) {
      res += triangle.area();
    }
  }

  return res;
}

void initRect(Rect &rect) {
  rect.upperLeft = Point(rect.lowerLeft.x, rect.upperRight.y);
  rect.lowerRight = Point(rect.upperRight.x, rect.lowerLeft.y);
  rect.corners.clear();
  rect.corners.push_back(rect.lowerLeft);
  rect.corners.push_back(rect.upperLeft);
  rect.corners.push_back(rect.upperRight);
  rect.corners.push_back(rect.lowerRight);
}

Point g(0, 0);

int ccw(Point &a, Point &b, Point &c) {
  double t = (b - a) % (c - b);
  return cmp(t, 0);
}

bool cmp1(Point &a, Point &b) {
  int t = ccw(g, a, b);
  if (t == 0) {
    return (a - g).len() < (b - g).len();
  }
  return t == 1;
}

bool inside(Point &p, Line seg) {
  Point &a = seg.A;
  Point &b = seg.B;
  return cmp((p - a).len() + (p - b).len(), (a - b).len()) == 0;
}

double solve1() {
  FOR (i, 1, n) if (rect[i].lowerLeft == g) return 0;

  vector<Point> ps;

  ps.push_back(bound.upperLeft);
  ps.push_back(bound.upperRight);
  ps.push_back(bound.lowerRight);

  FOR (i, 1, n) {
    for (auto &p : rect[i].corners) {
      ps.push_back(p);
    }
  }

  sort(ps.begin(), ps.end(), cmp1);

  vector<Line> lines;
  lines.push_back(Line(bound.upperLeft, bound.upperRight));
  lines.push_back(Line(bound.lowerRight, bound.upperRight));
  FOR (i, 1, n) {
    REP (j, 4) {
      int k = (j + 1) % 4;
      lines.push_back(Line(rect[i].corners[j], rect[i].corners[k]));
    }
  }

  int i = 0;
  double res = 0;
  while (i < ps.size()) {
    int j = i;

    while (j < ps.size() && ccw(g, ps[i], ps[j]) == 0) {
      j++;
    }

    if (j == ps.size()) {
      break;
    }

    Point &p = ps[i];
    Point &q = ps[j];

    Line l1(g, p);
    Line l2(g, q);

    double s = 1e18;
    for (auto &l3 : lines) {
      Point a;
      Point b;

      if (areIntersect(l1, l3, a) && areIntersect(l2, l3, b)) {
        if (inside(a, l3) && inside(b, l3)) {
          s = min(s, Tri(g, a, b).area());
        }
      }
    }

    res += s;

    i = j;
  }
  return res;
}

void rotate(double y, Rect &rec) {
  Point newLowerLeft = Point(y - rec.upperLeft.y, rec.upperLeft.x);
  Point newUpperRight = Point(y - rec.lowerRight.y, rec.lowerRight.x);
  rec.lowerLeft = newLowerLeft;
  rec.upperRight = newUpperRight;
  initRect(rec);
}

void rotate() {
  double y = bound.upperLeft.y;

  rotate(y, bound);
  FOR (i, 1, n) {
    rotate(y, rect[i]);
  }
}

int main() {
  int numt;
  cin >> numt;
  FOR (i, 1, numt) {
    bound.lowerLeft = Point(0, 0);
    cin >> bound.upperRight.x >> bound.upperRight.y;
    initRect(bound);

    cin >> n;
    FOR (i, 1, n) {
      cin >> rect[i].lowerLeft.x >> rect[i].lowerLeft.y >> rect[i].upperRight.x >> rect[i].upperRight.y;
      initRect(rect[i]);
    }

    double lowerLeft = solve1();
    rotate();
    double upperLeft = solve1();
    rotate();
    double upperRight = solve1();
    rotate();
    double lowerRight = solve1();

    printf("%.5lf %.5lf\n", upperLeft, upperRight);
    printf("%.5lf %.5lf\n", lowerLeft, lowerRight);
  }
}

