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

ll collatzlen(ll x) {
  ll t = 0;
  while (x > 1) {
    x = (x % 2) ? 3 * x + 1 : x / 2;
    t++;
  }
  return t;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll maxl = 9, maxn = 13;
  for (ll n = 14; n < 1000000; n++)
    if (collatzlen(n) > maxl) {
      maxl = collatzlen(n);
      maxn = n;
    }
  cout << maxn << "\n";
  return 0;
}