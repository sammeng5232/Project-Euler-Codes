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

bool isprime(ll k) {
  bool z = 1;
  for (ll i = 2; i * i <= k; i++)
    if (k % i == 0) {
      z = 0;
      break;
    }
  return z;
}

ll noofdiv(ll x) {
  ll cnt = 1;
  ll t = 0;
  ll y = x;
  for (ll j = 2; j <= x && j * j <= y + 1;
       j++) { // we set j*j<=y+1 since we know y is a tri. no.
    if (isprime(j)) {
      t = 0;
      while (x % j == 0) {
        t++;
        x /= j;
      }
      cnt *= (t + 1);
    }
  }
  return cnt;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n = 7;
  ll d; // find the first no. having over d divisors
  cin >> d;
  while (n) {
    if (noofdiv(n * (n + 1) / 2) > d) {
      cout << n * (n + 1) / 2 << "\n";
      return 0;
    }
    n++;
  }
}