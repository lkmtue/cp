#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define mod 1000000007

int f[100];
int a[100];
int sum = 0;

struct Node {
  Node(Node *next, int v): next(next), v(v), c(1) {}
  Node *next;
  int v;
  int c;
};

const int key = 100007;
struct HashMap {
  Node *head[key];
  int size;

  HashMap() {
    size = 0;
    for (int i = 0; i < key; i++) {
      head[i] = NULL;
    }
  }

  void inc(int x) {
    int k = x % key;
    Node* p = head[k];
    while (p) {
      if (p->v == x) {
        p->c++;
        return;
      }
      p = p->next;
    }
    p = new Node(head[k], x);
    head[k] = p;
  }

  int get(int x) {
    Node* p = head[x % key];
    while (p) {
      if (p->v == x) {
        return p->c;
      }
      p = p->next;
    }
    return 0;
  }
};

HashMap cnt[2][11];
int t;
int limit;

HashMap m;

vector<int> s[11];

void attempt(int x) {
  if (t == 1 && !cnt[t][x - 1].get(sum)) {
    s[x - 1].push_back(sum);
  }
  cnt[t][x - 1].inc(sum);

  if (x > 10) {
    return;
  }

  for (int i = a[x - 1]; i < limit && sum + f[i] <= 1000000000; i++) {
    a[x] = i;
    sum += f[i];
    attempt(x + 1);
    sum -= f[i];
  }
}

int main() {
  f[0] = 1;
  f[1] = 2;

  for (int i = 2; i < 43; i++) {
    f[i] = f[i - 1] + f[i - 2];
  }

  a[0] = 0;
  t = 0;
  limit = 21;
  attempt(1);

  a[0] = 21;
  t = 1;
  limit = 43;
  attempt(1);

  for (int i = 0; i <= 10; i++) {
    sort(s[i].begin(), s[i].end());
  }

  int q;
  cin >> q;
  while (q--) {
    int x, k;
    cin >> x >> k;
    int res = 0;
    for (int i = 0; i <= k; i++) {
      for (int j = 0; j < s[i].size() && s[i][j] <= x; j++) {
        long long temp = cnt[0][k - i].get(x - s[i][j]);
        if (temp) {
          res = (res + temp * cnt[1][i].get(s[i][j])) % mod;
        }
      }
    }
    cout << res << endl;
  }
}
