#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef stack<ll> sl;
typedef stack<int> si;
typedef queue<ll> ql;
typedef queue<int> qi;
typedef map<int, int> mii;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n = 15, a[16][16], currs, maxs = 0;
  for (int i = 1; i <= 15; i++)
    for (int j = 1; j <= i; j++)
      cin >> a[i][j];
  for (int k = 0; k < 16384; k++) {
    int i = 1, j = 1, l = k;
    currs = a[i][j];
    for (int i = 2; i <= 15; i++) {
      j += l % 2;
      currs += a[i][j];
      l /= 2;
    }
    maxs = max(maxs, currs);
  }
  cout << maxs << "\n";
  return 0;
}
