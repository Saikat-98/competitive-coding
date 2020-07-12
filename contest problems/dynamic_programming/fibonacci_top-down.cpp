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

int fib(int n, int dp[])
{
  if (n == 0 || n == 1)
    return n;
  if (dp[n] != 0)
    return dp[n];
  int ans = fib(n - 1, dp) + fib(n - 2, dp);
  return dp[n] = ans;
}

int main()
{
  fastIO();
  int n;
  cin >> n;
  int dp[n + 1] = {0};
  cout << fib(n, dp);
  return 0;
}