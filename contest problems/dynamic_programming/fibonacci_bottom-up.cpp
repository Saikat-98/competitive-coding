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
  dp[1] = 1;
  for (int i = 2; i <= n; i++)
    dp[i] = dp[i - 1] + dp[i - 2];
  return dp[n];
}

int fibSpaceOptimized(int n)
{
  if (n == 0 || n == 1)
    return n;
  int a = 0, b = 1, c = 0;
  for (int i = 2; i <= n; i++)
  {
    c = a + b;
    a = b;
    b = c;
  }
  return c;
}

int main()
{
  fastIO();
  int n;
  cin >> n;
  int dp[n + 1] = {0};
  cout << fib(n, dp) << "\n";
  cout << fibSpaceOptimized(n);
  return 0;
}