#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

#define base 1000000007
#define MAX 1111

int n, m, s;
int a[MAX];
int f[MAX][MAX];

inline void update(int &x, int y) {
  x += y;
  if (x >= base) x -= base;
}

int main() {
  int numt;
  cin >> numt;
  while (numt--) {
    cin >> n >> m >> s;
    for (int i = 1; i <= m; i++) {
      cin >> a[i];
    }

    memset(f, 0, sizeof(f));

    f[0][s] = 1;
    for (int i = 0; i < m; i++) {
      for (int j = 1; j <= n; j++) {
        int k = j - a[i + 1];
        if (1 <= k) {
          update(f[i + 1][k], f[i][j]);
        }
        k = j + a[i];
        if (k <= n) {
          update(f[i + 1][k], f[i][j]);
        }
      }
    }
    for (int j = 1; j <= n; j++) {
      cout << f[m][j] << " ";
    }
    cout << endl;
  }
}
