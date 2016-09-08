#include <algorithm>
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

#define MAX 111
#define oo 1000111000

int n;
int a[MAX], f[MAX][3];

int main() {
  while (cin >> n) {
    FOR (i, 1, n) {
      cin >> a[i];
      bool gym = a[i] & 2;
      bool contest = a[i] & 1;

      // rest.
      f[i][0] = min(f[i - 1][0], min(f[i - 1][1], f[i - 1][2])) + 1;
      
      if (contest) {
        f[i][1] = min(f[i - 1][0], f[i - 1][2]);
      } else {
        f[i][1] = oo;
      }

      if (gym) {
        f[i][2] = min(f[i - 1][0], f[i - 1][1]);
      } else {
        f[i][2] = oo;
      }
    } 

    cout << min(f[n][0], min(f[n][1], f[n][2])) << endl;
  }
}

