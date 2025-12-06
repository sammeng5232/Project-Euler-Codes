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
  for (int i = 2; i * i <= k; i++)
    if (k % i == 0) {
      z = 0;
      break;
    }
  return z;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int cnt = 0;
  ll k; // find the sum of primes below k
  cin >> k;
  ll s = 0;
  ll n = 2;
  while (n < k) {
    if (isprime(n)) {
      cnt++;
      s += n;
    }
    n++;
  }
  cout << s << "\n";
  return 0;
}