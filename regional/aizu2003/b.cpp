#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

int f[33000][200][5];

int main() {
  f[0][0][0] = 1;

  for (int i = 0; i <= (1 << 15); i++) {
    for (int j = 1; j <= 199; j++) {
      if (i == 0) f[i][j][0] = 1;

      for (int k = 1; k <= 4; k++) {
        f[i][j][k] = f[i][j - 1][k];
        if (i >= j * j) {
          f[i][j][k] += f[i - j * j][j][k - 1];
        }
      }
    }
  }

  while (1) {
    int x;
    cin >> x;

    if (x == 0) break;

    int s = (int)(sqrt(x) + 1e-6);

    int r = 0;
    for (int k = 1; k <= 4; k++) r += f[x][s][k];
    cout << r << endl;

  }
}
