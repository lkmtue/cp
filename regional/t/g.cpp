#include <cstdio>
#include <iostream>

using namespace std;

#define MAX 100111

typedef pair<int,int> Point;

int m, n;

Point a[MAX];
Point b[MAX];

int update(int x) {
  x++;
  while (x < 100000) {
    tree[x]++;
    x += x & (-x);
  }
}

int get(int x) {
  x++;
  int sum = 0;
  while (x > 0) {
    sum += tree[x];
    x -= x & (-x);
  }
  return sum;
}

int dist(Point a, Point b) {
  return abs(a.first - b.first) + abs(a.second - b.second);
}

int main() {
  int _;
  cin >> _;

  while (_--) {
    cin >> m >> n;

    for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;

    for (int i = 0; i < n; i++) {
      b[i].first = dist(a[i], a[0]);
      b[i].second = dist(a[i], a[1]);
    }

    sort(b, b + n);

    int res = n;
    int i = 0;

    while (i < n) {
      int j = i;

      while (j + 1 < n && b[i] == b[j]) {
        update(b[i].second);
        j++;
      }

      int g = get(b[i].second);

      if (i < j || g > 0) {
        res--;
      }

      i = j + 1;
    }

    cout << res << endl;
  }
}
