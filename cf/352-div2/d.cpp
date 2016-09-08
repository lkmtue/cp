#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

#define MAXN 500111
#define ll long long

int a[MAXN];

int main() {
  int n, k;

  scanf("%d%d", &n, &k);

  ll sum = 0;

  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    sum += a[i];
  }

  int low = 0;
  int high = sum / n;
  int x = 0;

  while (low <= high) {
    int mid = (low + high) / 2;

    ll sum = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] < mid) {
        sum += mid - a[i];
      }
    }

    if (sum <= k) {
      x = mid;
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }

  low = sum / n + (sum % n == 0 ? 0 : 1);
  high = 1000111000;
  int y = 0;
  while (low <= high) {
    int mid = (low + high) / 2;
    ll sum = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] > mid) {
        sum += a[i] - mid;
      }
    }

    if (sum <= k) {
      y = mid;
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }

  if (x <= y) {
    cout << y - x << endl;
  } else {
    if (sum % n == 0) {
      cout << 0 << endl;
    } else {
      cout << 1 << endl;
    }
  }
}
