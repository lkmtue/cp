
#include <cstdio>
#include <iostream>

using namespace std;

typedef long long ll;

#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FORN(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) for (int i = 0; i < (n); i++)
#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
#define BUG(x) cerr << #x << " = " << x << endl

int a[1111];

int main() {
  int n;
  cin >> n;
  int sum = 0;
  REP (i, n) { 
    cin >> a[i];
    sum += a[i];
  }

  bool ok;
  if (n == 1) {
    ok = sum == 1;
  } else {
    ok = sum == n - 1;
  }
  cout << (ok ? "YES" : "NO") << endl;
}

