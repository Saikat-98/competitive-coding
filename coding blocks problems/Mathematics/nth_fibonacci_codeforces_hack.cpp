// Recurrence is : -
// 1. 'n' is odd :- f(n) = f(n/2)*f((n/2)+1) + f(n/2)*f((n/2)-1)
// 2. 'n' is even :- f(n) = f(n/2)*f(n/2) + f((n/2)-1)*f((n/2)-1)

//O(logn * loglogn)

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define setbits(x) __builtin_popcountll(x)
#define tz(x) __builtin_ctzll(x)
#define lz(x) __builtin_clzll(x)
#define fsetbit(x) ffsll(x)
#define mod 1000000007
#define inf 1e18
#define w(x) \
  int x;     \
  cin >> x;  \
  while (x--)
#define debug(x, val) cout << "The value of " << x << " is: " << val << "\n";
#define op(x) cout << x << "\n";
void fastIO()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

ll fib(long n, map<ll, ll> &m)
{
	if (m.count(n))
		return m[n];
	ll k = n / 2;
	if (n & 1)
		m[n] = (fib(k, m) * fib(k - 1, m) + fib(k + 1, m) * fib(k, m) % mod);
	else
		m[n] = (fib(k, m) * fib(k, m) + fib(k - 1, m) * fib(k - 1, m) % mod);
	return m[n];
}

int main()
{
	fastIO();
	ll n;
	map<ll, ll> m;
	m[0] = m[1] = 1;
	cin >> n;
	while (n--)
		cout << ((n == 0) ? 0 : fib(n - 1, m)) << "\n";
	return 0;
}