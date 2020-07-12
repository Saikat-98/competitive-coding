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

int minStepsBottomUp(int n, int dp[])
{
  if (n == 1)
    return 0;

  for (int i = 2; i <= n; i++)
  {
    int op1 = INT_MAX, op2 = INT_MAX, op3 = INT_MAX;
    if (i % 3 == 0)
      op1 = dp[i / 3];
    if (i % 2 == 0)
      op2 = dp[i / 2];
    op3 = dp[i - 1];
    dp[i] = min(min(op1, op2), op3) + 1;
  }
  return dp[n];
}

int main()
{
  fastIO();
  int n;
  cin >> n;
  int dp[n + 1] = {0};
  cout << minStepsBottomUp(n, dp);
  return 0;
}