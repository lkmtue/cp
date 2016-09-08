#include <cstdio>
#include <iostream>
#include <set>

using namespace std;
int n, total, a[100111];

bool check(int limit) {
  long long x = 0, y = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] > limit) {
      x += a[i] - limit;
    }
    if (a[i] < limit) {
      y += limit - a[i];
    }
  }
  return x <= y && x <= total;
}

int main() {
  ios::sync_with_stdio(false);
  cin >> n >> total;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int low = 0, high = 1000000000, res = -1;
  while (low <= high) {
    int mid = (low + high) / 2;
    if (check(mid)) {
      res = mid;
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }

  cout << res << endl;
}
