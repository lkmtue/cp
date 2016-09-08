#include <cstdio>
#include <iostream>
#include <set>
#include <cmath>
#include <vector>

using namespace std;

#define ll long long
#define sqr(x) ((x) * (x))

double dist(ll x, ll y, ll a, ll b) {
  return sqrt(sqr(x - a) + sqr(y - b));
}

int main() {
  ios::sync_with_stdio(false);
  ll ax, ay, bx, by, tx, ty;
  cin >> ax >> ay >> bx >> by >> tx >> ty;
  int n;
  cin >> n;

  if (n == 1) {
    ll x, y;
    cin >> x >> y;
    double d1 = dist(x, y, ax, ay) + dist(x, y, tx, ty);
    double d2 = dist(x, y, bx, by) + dist(x, y, tx, ty);
    printf("%.10lf", min(d1, d2));
  } else {
    double total = 0;

    vector<pair<double, double> > v;
    multiset<double> s;
    for (int i = 0; i < n; i++) {
      ll x, y;
      cin >> x >> y;
      total += 2 * dist(x, y, tx, ty);
      double da = dist(x, y, ax, ay) - dist(x, y, tx, ty);
      double db = dist(x, y, bx, by) - dist(x, y, tx, ty);
      v.push_back(make_pair(da, db));
      s.insert(db);
    }

    double best = 1e30;
    for (int i = 0; i < n; i++) {
      s.erase(s.find(v[i].second));
      best = min(best, total + v[i].first + (*s.begin()));
      best = min(best, total + v[i].first);
      best = min(best, total + v[i].second);
      s.insert(v[i].second);
    }
    printf("%.10lf", best);
  }
}
