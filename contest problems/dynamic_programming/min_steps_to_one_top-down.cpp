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

int minStepsTopDown(int n, int dp[])
{
  if (n == 1)
    return 0;

  if (dp[n] != 0)
    return dp[n];

  int op1 = INT_MAX, op2 = INT_MAX, op3 = INT_MAX;
  if (n % 3 == 0)
    op1 = minStepsTopDown(n / 3, dp);
  if (n % 2 == 0)
    op2 = minStepsTopDown(n / 2, dp);
  op3 = minStepsTopDown(n - 1, dp);
  dp[n] = min(min(op1, op2), op3) + 1;
  return dp[n];
}

int main()
{
  fastIO();
  int n;
  cin >> n;
  int dp[n + 1] = {0};
  cout << minStepsTopDown(n, dp);
  return 0;
}