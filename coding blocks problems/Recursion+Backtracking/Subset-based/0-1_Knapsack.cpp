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

int profit(int N, int C, int *wt, int *prices)
{
  if (N == 0 || C == 0)
    return 0;

  //Recursive Case
  int inc, exc;
  inc = exc = INT_MIN;
  if (wt[N - 1] <= C)
    inc = prices[N - 1] + profit(N - 1, C - wt[N - 1], wt, prices);
  exc = profit(N - 1, C, wt, prices);

  return max(inc, exc);
}

int main()
{
  fastIO();
  int weight[] = {1, 2, 3, 5};
  int prices[] = {40, 20, 30, 100};

  int N = 4;
  int C = 7;

  cout << profit(N, C, weight, prices);
  return 0;
}