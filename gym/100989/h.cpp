#include <cstdio>
#include <iostream>

using namespace std;


int main() {
  int n;
  cin >> n;

  int s1 = 0;
  int s5 = 0;
  int s10 = 0;
  int s20 = 0;
  int s50 = 0;

  for (int i = 0; i < n; i++) {
    int k, n1, n5, n10, n20, n50;
    cin >> k >> n1 >> n5 >> n10 >> n20 >> n50;
    int change = k - n1 - 5 * n5 - 10 * n10 - 20 * n20 - 50 * n50;
    s1 += n1;
    s5 += n5;
    s10 += n10;
    s20 += n20;
    s50 += n50;
    // cout << s1 << " " << s5 << " " << s10 << " " << s20 << " " << s50 << endl;

    k = n1 + 5 * n5 + 10 * n10 + 20 * n20 + 50 * n50 - k;
    // cout << k << " " << endl;

    int u50 = min(s50, u50 / 50);
    bool ok = false;
    for (;u50 >= 0; u50--) {
      int r = k - u50 * 50;
      r -= min(s20, r / 20) * 20;
      r -= min(s10, r/ 10) * 10;
      r -= min(s5, r / 5) * 5;
      r -= min(s1, r);

      if (r == 0) {
        ok = true;
        break;
      }
    }

    if (!ok) {
      cout << "no" << endl;
      return 0;
    }

    int r = k - u50 * 50;
    s50 -= u50;

    int u20 = min(s20, r / 20);
    r -= u20 * 20;
    s20 -= u20;

    int u10 = min(s10, r / 10);
    r -= u10 * 10;
    s10 -= u10;

    int u5 = min(s5, r / 5);
    r -= u5 * 5;
    s5 -= u5;

    int u1 = min(s1, r);
    r -= u1;
    s1 -= u1;

    // cout << u1 << " " << u5 << " " << u10 << " " << u20 << " " << u50 << endl;
  }
  cout << "yes" << endl;
}
