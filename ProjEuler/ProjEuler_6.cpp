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

ll f(ll k) {
  return (k * (k + 1) / 2) * (k * (k + 1) / 2) - k * (k + 1) * (2 * k + 1) / 6;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << f(100) << "\n";
  return 0;
}