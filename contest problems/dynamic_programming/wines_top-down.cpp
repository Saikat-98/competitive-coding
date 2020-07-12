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

int wines(int i, int j, int year, int winesArray[], int dp[100][100])
{
  if (i > j)
    return 0;

  if (dp[i][j] != 0)
    return dp[i][j];

  int op1 = winesArray[i] * year + wines(i + 1, j, year + 1, winesArray, dp);
  int op2 = winesArray[j] * year + wines(i, j - 1, year + 1, winesArray, dp);
  return dp[i][j] = max(op1, op2);
}

int main()
{
  fastIO();
  int n, val;
  cin >> n;
  int winesArray[n];
  for (int i = 0; i < n; i++)
  {
    cin >> val;
    winesArray[i] = val;
  }
  int dp[100][100] = {0};
  cout << wines(0, n - 1, 1, winesArray, dp);
  return 0;
}