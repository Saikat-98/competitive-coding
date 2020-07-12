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

int coinsExchange(int coins[], int amount, int n, int dp[])
{
  if (amount == 0)
    return 0;

  if (dp[amount] != 0)
    return dp[amount];

  int ans = INT_MAX;
  for (int i = 1; i <= n; i++)
    if (amount - coins[i] >= 0)
    {
      int temp = coinsExchange(coins, amount - coins[i], n, dp);
      ans = min(temp + 1, ans);
    }
  dp[amount] = ans;
  return dp[amount];
}

int main()
{
  fastIO();
  int n, val, amount;
  cin >> n;
  int coins[n + 1];
  for (int i = 1; i <= n; i++)
  {
    cin >> val;
    coins[i] = val;
  }
  cin >> amount;
  int dp[100] = {0};
  cout << coinsExchange(coins, amount, n, dp);
  return 0;
}