#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
#include <cmath>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FORN(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) for (int i = 0; i < (n); i++)
#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
#define BUG(x) cerr << #x << " = " << x << endl

#define MAX 55

const double EPS = 1e-7;
inline int cmp(double a, double b) {
    return (a < b - EPS) ? -1 : ((a > b + EPS) ? 1 : 0);
}

struct Point {
  double x, y;
  Point(double x = 0.0, double y = 0.0) : x(x), y(y) {}

  Point operator + (Point a) { return Point(x+a.x, y+a.y); }
  Point operator - (Point a) { return Point(x-a.x, y-a.y); }
  Point operator * (double k) { return Point(x*k, y*k); }
  Point operator / (double k) { return Point(x/k, y/k); }

  double operator * (Point a) { return x*a.x + y*a.y; } // dot product
  double operator % (Point a) { return x*a.y - y*a.x; } // cross product

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

struct Circle : Point {
  double r;
  Circle(double x = 0, double y = 0, double r = 0) : Point(x, y), r(r) {}
  Circle(Point p, double r) : Point(p), r(r) {}
  
  bool contains(Point p) { return (*this - p).len() <= r + EPS; }
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

bool areIntersect(Circle u, Circle v) {
  if (cmp((u - v).len(), u.r + v.r) > 0) return false;
  if (cmp((u - v).len() + v.r, u.r) < 0) return false;
  if (cmp((u - v).len() + u.r, v.r) < 0) return false;
  return true;
}

void circleIntersect(Circle u, Circle v, vector<Point> &result) {
  if (!areIntersect(u, v)) return;
  double d = (u - v).len();
  double alpha = acos((u.r * u.r + d*d - v.r * v.r) / 2.0 / u.r / d);

  Point p1 = (v - u).rotate(alpha);
  Point p2 = (v - u).rotate(-alpha);
  result.push_back(p1 / p1.len() * u.r + u);
  result.push_back(p2 / p2.len() * u.r + u);
}

void circleLineIntersect(Line l, Circle cir, vector<Point> &res) {
  double r = cir.r, a = l.a, b = l.b, c = l.c + l.a*cir.x + l.b*cir.y;

  double x0 = -a*c/(a*a+b*b),  y0 = -b*c/(a*a+b*b);
  if (c*c > r*r*(a*a+b*b)+EPS) {
    return;
  } else if (fabs(c*c - r*r*(a*a+b*b)) < EPS) {
    res.push_back(Point(x0, y0) + Point(cir.x, cir.y));
    return;
  } else {
    double d = r*r - c*c/(a*a+b*b);
    double mult = sqrt (d / (a*a+b*b));
    double ax,ay,bx,by;
    ax = x0 + b * mult;
    bx = x0 - b * mult;
    ay = y0 - a * mult;
    by = y0 + a * mult;

    res.push_back(Point(ax, ay) + Point(cir.x, cir.y));
    res.push_back(Point(bx, by) + Point(cir.x, cir.y));
    return;
  }
}

double w, h;
int n;
vector<Circle> circles;

bool check(double mid) {
  vector<Point> points;

  Line l1(Point(mid, mid), Point(w - mid, mid));
  Line l2(Point(mid, mid), Point(mid, h - mid));
  Line l3(Point(w - mid, mid), Point(w - mid, h - mid));
  Line l4(Point(mid, h - mid), Point(w - mid, h - mid));

  for (auto ci : circles) {
    ci.r += mid;
    for (auto cj : circles) {
      cj.r += mid;
      circleIntersect(ci, cj, points);
    }

    circleLineIntersect(l1, ci, points);
    circleLineIntersect(l2, ci, points);
    circleLineIntersect(l3, ci, points);
    circleLineIntersect(l4, ci, points);
  }

  for (auto &p : points) {
    bool inside = mid - EPS < p.x && p.x < w - mid + EPS 
                    && mid - EPS < p.y && p.y < h - mid + EPS;

    if (inside) {
      bool ok = true;

      for (auto c : circles) {
        double d = (p - c).len();
        if (d + EPS < c.r + mid) {
          ok = false;
          break;
        }
      }

      if (ok) {
        return true;
      }
    }
  }
  return false;
}

int main() {
  int numt;
  cin >> numt;

  while (numt--) {
    cin >> w >> h;
    cin >> n;

    circles.clear();

    REP (_, n) {
      Circle c;
      cin >> c.x >> c.y >> c.r;
      circles.push_back(c);
    }

    if (n == 0) {
      printf("%.10lf\n", min(w / 2, h / 2));
      continue;
    }
    
    double low = 0;
    double high = min(w, h) / 2;

    REP (_, 50) {
      double mid = (low + high) / 2;
      if (check(mid)) {
        low = mid;
      } else {
        high = mid;
      }
    }

    printf("%.10lf\n", (low + high) / 2);
  }
}

