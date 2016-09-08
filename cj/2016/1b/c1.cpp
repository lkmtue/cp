#include <cstdio>
#include <iostream>
#include <map>

using namespace std;

#include <string.h>

#define M 1111
#define N 1111
bool graph[M][N];
bool seen[N];
int matchL[M], matchR[N];
int n, m;

bool bpm(int u){
    for (int v = 0; v < n; v++) {
      if (graph[u][v]) {
        if (seen[v]) continue;
        seen[v] = true;
        if (matchR[v] < 0 || bpm(matchR[v])){
            matchL[u] = v;
            matchR[v] = u;
            return true;
        }
      }
    }
    return false;
}

int match() {
    // Read input and populate graph[][]
    // Set m, n
    memset(matchL, -1, sizeof(matchL));
    memset(matchR, -1, sizeof(matchR));

    int cnt = 0;

    for (int i = 0; i < m; i++) {
        memset(seen, 0, sizeof(seen));
        if (bpm(i)) {
          cnt++;
        }
    }
    return cnt;
}

int main() {
  int ntest;
  cin >> ntest;

  for (int t = 0; t < ntest; t++) {
    int nn;
    cin >> nn;

    map<string, int> x, y;

    for (int i = 0; i < M; i++) {
      for (int j = 0; j < N; j++) {
        graph[i][j] = false;
      }
    }

    for (int i = 0; i < nn; i++) {
      string s, t;
      cin >> s >> t;

      if (x.find(s) == x.end()) {
        x[s] = x.size();
      }

      if (y.find(t) == y.end()) {
        y[t] = y.size();
      }

      graph[x[s]][y[t]] = true;
    }

    m = x.size();
    n = y.size();

    int res = nn - max(m, n) - (min(m, n) - match());

    cout << "Case #" << t + 1 << ": " << res << endl;
  }
}
