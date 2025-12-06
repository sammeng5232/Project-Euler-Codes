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

bool abun[28124], gd[28124];

bool isprime(ll k) {
  bool z = 1;
  for (ll i = 2; i * i <= k; i++)
    if (k % i == 0) {
      z = 0;
      break;
    }
  return z;
}

ll sumofpropdiv(ll x) {
  ll rs = 1;
  ll t = 0;
  ll y = x;
  for (ll j = 2; j <= x; j++) {
    if (isprime(j)) {
      t = 0;
      while (x % j == 0) {
        t++;
        x /= j;
      }
      rs *= (pow(j, t + 1) - 1) / (j - 1);
    }
  }
  return rs - y;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll s = 0;
  for (int i = 12; i <= 28123; i++)
    if (sumofpropdiv(i) > i)
      abun[i] = 1;
  for (int i = 12; i <= 14061; i++)
    for (int j = i; i + j <= 28123; j++)
      if (abun[i] && abun[j])
        gd[i + j] = 1;
  for (int i = 1; i <= 28123; i++)
    if (!gd[i])
      s += i;
  cout << s << "\n";
  return 0;
}