#include <algorithm>
#include <cmath>
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

long long n, r, p, dp[1000006];

long long solve(long long x) {
  if (~dp[x]) return dp[x];
  dp[x] = (1ll << 60);
  for (int i = 2; i * i <= x; i++) {
    long long tmp = (i - 1) * p + r + solve((x + i - 1) / i);
    dp[x] = min(dp[x], tmp);
  }
  for (int i = 1; i * i <= x; i++) {
    long long tmp = r + solve(i) + p * ((x - 1 + i) / i - 1);
    dp[x] = min(dp[x], tmp);
  }
  return dp[x];
}

int main() {
  cin >> n >> r >> p;
  memset(dp, -1, sizeof(dp));
  dp[1] = 0; 
  cout << solve(n);
}

