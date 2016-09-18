vector<int> graph[MAXN];
int matchX[MAXN], matchY[MAXN], used[MAXN], start;
bool found;

void dfs(int u) {
  used[u] = start;
  for (int v : graph[u]) {
    if (!matchY[v]) found = true;
    else if (used[matchY[v]] != start) dfs(matchY[v]);

    if (found) {
      matchX[u] = v;
      matchY[v] = u;
      return;
    }
  }
}

int main() {
  FOR (i, 1, n) {
    if (!matchX[i]) {
      start = i;
      found = false;
      dfs(i);
    }
  }

  int res = 0;
  FOR (i, 1, n) if (matchX[i]) res++;
}
