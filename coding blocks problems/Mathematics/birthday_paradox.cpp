// What is the minimum number of people that should be present in a hall so that there's 50% chance of two people having the same birthday?

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

int main()
{
  fastIO();

  float x = 1.0;
  int people = 0;
  float num = 365, denom = 365;

  float p;
  cin >> p;

  if (p == 1.0)
  {
    op("366");
    return 0;
  }

  while (x > (1 - p))
  {
    x *= (num / denom);
    num--, people++;
  }
  debug("People", people);
  debug("x", x);

  return 0;
}