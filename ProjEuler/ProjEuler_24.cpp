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

int a[10];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  for (int i = 0; i < 10; i++)
    a[i] = i;
  int c = 1;
  while (next_permutation(a, a + 10)) {
    c++;
    if (c == 1e6)
      break;
  }
  for (int i = 0; i < 10; i++)
    cout << a[i];
  return 0;
}