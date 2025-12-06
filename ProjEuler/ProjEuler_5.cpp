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

ll valid(ll k) {
  bool z = 1;
  for (int i = 2; i <= 19; i++)
    if (k % i != 0)
      z = 0;
  return z;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n = 2520 * 11 * 13 * 17 * 19;
  while (n >= 0) {
    if (valid(n)) {
      cout << n << "\n";
      return 0;
    } else
      n += 2520 * 11 * 13 * 17 * 19;
  }
}