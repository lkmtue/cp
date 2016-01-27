#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAX 1111

struct Book {
  int start, end, price;
} book[MAX];

int f[MAX][MAX];

bool cmp(Book a, Book b) {
  return a.end < b.end;
}

int main() {

  while (1) {
    int n;

    cin >> n;

    if (n == 0) break;

    for (int i = 0; i < n; i++) {
      cin >> book[i].start >> book[i].end >> book[i].price;
    }

    memset(f, -1, sizeof(f));

    sort(book, book + n, cmp);

    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        f[i][j] = book[i].price + book[j].price;
      }
    }

    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        for (int k = i + 1; k < j && k < i + 200; k++) if (book[k].start > book[i].end) {
          f[k][j] = max(f[k][j], f[i][j] + book[k].price);
        }

        for (int k = j + 1; k < n && k < j + 200; k++) if (book[k].start > book[i].end) {
          f[j][k] = max(f[j][k], f[i][j] + book[k].price);
        }
      }
    }

    int r = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        r = max(r, f[i][j]);
      }
    }

    cout << r << endl;
  }
}
