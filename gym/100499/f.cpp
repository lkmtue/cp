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

#define MAXN 200111

struct Node {
    Node *left, *right, *father;
    int size, key, sum, lab;
} *root, *sentinel;
// Must call initTree before using splay tree
void initTree() {
    sentinel = new Node;
    sentinel -> left = sentinel -> right = sentinel -> father = sentinel;
    sentinel -> size = 0;
    sentinel -> key = sentinel -> sum = 0;
}
void setLink(Node *x, Node *y, bool left) {
    if (left) x -> left = y;
    else x -> right = y;
    y -> father = x;
}
void update(Node *x) {
    x -> size = x -> left -> size + x -> right -> size + 1;
    x -> sum = x->key + x->left->sum + x->right->sum;
}
void upTree(Node *x) {
    Node *y = x -> father;
    Node *z = y -> father;
    Node *tmp;
    if (y->right == x) {
        tmp = x -> left;
        setLink(x, y, true);
        setLink(y, tmp, false);
    }
    else {
        tmp = x -> right;
        setLink(x, y, false);
        setLink(y, tmp, true);
    }
    setLink(z, x, z->left == y);
    update(y); update(x);
}
void splay(Node *x) {
    while (1) {
        Node *y = x -> father;
        if (y == sentinel) return ;
        Node *z = y -> father;
        if (z != sentinel)
            if ((z->right == y) == (y->right == x)) upTree(y);
            else upTree(x);
        upTree(x);
    }
}

Node *join(Node *t1, Node *t2) {
    if (t1 == sentinel) return t2;
    if (t2 == sentinel) return t1;
    while (1) {
        //refine(t1); // Used for range cover
        if (t1 -> right == sentinel) break;
        t1 = t1 -> right;
    }
    splay(t1);
    setLink(t1, t2, false);
    update(t1);
    return t1;
}

int n, cnt;
pair<int, int> list[MAXN];
vector<int> a[MAXN];
Node* discover[MAXN];
Node* finish[MAXN];

void dfs(int u) {
  list[++cnt] = make_pair(u, 1);

  REP (i, a[u].size()) {
    dfs(a[u][i]);
  }

  list[++cnt] = make_pair(u, 0);
}

Node* construct(int i, int j) {
  if (i > j) {
    return sentinel;
  }

  int k = (i + j) / 2;

  Node* t = new Node();
  t->lab = list[k].first;
  t->key = list[k].second;

  Node *l = construct(i, k - 1);
  Node *r = construct(k + 1, j);
  
  setLink(t, l, true);
  setLink(t, r, false);
  t->father = sentinel;
  update(t);

  if (t->key == 1) {
    discover[t->lab] = t;
  } else {
    finish[t->lab] = t;
  }

  return t;
}

void init() {
  cnt = 0;
  dfs(1);
  root = construct(1, 2 * n);
  root->father = sentinel;
}

Node* cutLeft(Node* root) {
  Node* u = root->left;
  root->left = sentinel;
  u->father = sentinel;
  update(root);
  return u;
}

Node* cutRight(Node* root) {
  Node* u = root->right;
  root->right = sentinel;
  u->father = sentinel;
  update(root);
  return u;
}

void updateTree(int u, int v) {
  // Split.
  Node *x = discover[u];
  splay(x);
  Node *t1 = cutLeft(x);
  Node *y = finish[u];
  splay(y);
  Node *t2 = cutRight(y);
  root = join(t1, t2);

  // Join.
  Node *z = finish[v];
  splay(z);
  t1 = cutLeft(z);
  root = join(t1, y);
  root = join(root, z);
}

Node* find(Node* t, int k) {
  if (t->left->sum >= k) {
    return find(t->left, k);
  }

  k -= t->left->sum;

  if (t->key == 1 && k == 1) {
    return t;
  }

  k -= t->key;

  return find(t->right, k);
}

int solve(int k) {
  Node* t = find(root, k);
  splay(t);
  root = t;
  return t->lab;
}

int main() {
  ios::sync_with_stdio(false);
  initTree();
  int numT;
  cin >> numT;
  while (numT--) {
    cin >> n;
    FOR (i, 1, n - 1) {
      int u, v;
      cin >> u >> v;
      a[u].push_back(v);
    }

    init();

    int q;
    cin >> q;
    REP (i, q) {
      int k, u, v;
      cin >> k;
      if (k == 1) {
        cin >> u >> v;
        updateTree(u, v);
      } else {
        cin >> k;
        cout << solve(k) << endl;
      }
    }

    FOR (i, 1, n) {
        a[i].clear();
        delete discover[i];
        delete finish[i];
    }
  }
}

