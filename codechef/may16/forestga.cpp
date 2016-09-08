#include <cstdio>
#include <iostream>

using namespace std;

#define MAX 100111
#define ll long long
#define oo 1000111000111000111LL

int n;
ll w, l;
ll h[MAX], r[MAX];

bool ok(ll m) {
  ll t = 0;
  for (int i = 0; i < n; i++) {
    ll temp;
    if ((oo - h[i]) / r[i] < m + 1) {
      temp = oo;
    } else {
      temp = h[i] + m * r[i];
    }
    if (temp >= l) {
      t += temp;
    }
    t = min(t, oo);
  }
  return t >= w;
}

int main() {
  cin >> n >> w >> l;

  for (int i = 0; i < n; i++) {
    cin >> h[i] >> r[i];
  }

  ll low = 0;
  ll high = oo;
  ll res = -1;

  while (low <= high) {
    ll mid = (low + high) / 2;
    if (ok(mid)) {
      res = mid;
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }

  cout << res << endl;
}
