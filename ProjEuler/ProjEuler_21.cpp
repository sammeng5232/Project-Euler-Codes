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

bool amic[10000];
int s = 0;

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
  for (int i = 2; i < 10000; i++)
    if (i != sumofpropdiv(i) && sumofpropdiv(i) < 10000 &&
        sumofpropdiv(sumofpropdiv(i)) == i)
      amic[i] = amic[sumofpropdiv(i)] = 1;
  for (int i = 2; i < 10000; i++)
    s += amic[i] * i;
  cout << s << "\n";
  return 0;
}
