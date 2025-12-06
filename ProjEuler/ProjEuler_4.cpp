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

ll ispalindrome(ll k) {
  string s = to_string(k);
  int l = s.length();
  bool z = 1;
  for (int i = 0; i <= l / 2; i++)
    if (s[i] != s[l - 1 - i])
      z = 0;
  return z;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n = 1;
  for (ll x = 100; x < 1000; x++)
    for (ll y = 100; y < 1000; y++)
      if (ispalindrome(x * y))
        n = max(n, x * y);
  cout << n << "\n";
  return 0;
}