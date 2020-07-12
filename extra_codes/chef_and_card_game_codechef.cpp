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

long sum(long no)
{
  long sum = 0;
  while (no > 0)
  {
    sum += no % 10;
    no /= 10;
  }
  return sum;
}

int main()
{
  fastIO();
  w(t)
  {
    int n, winnerM = 0, winnerC = 0;
    cin >> n;
    while (n--)
    {
      long a, b;
      cin >> a >> b;
      long sa = sum(a);
      long sb = sum(b);
      if (sa > sb)
        winnerC++;
      else if (sa < sb)
        winnerM++;
      else
      {
        winnerC++;
        winnerM++;
      }
    }
    if (winnerC > winnerM)
      cout << "0 " << winnerC << "\n";
    else if (winnerC < winnerM)
      cout << "1 " << winnerM << "\n";
    else
      cout << "2 " << winnerC << "\n";
  }
  return 0;
}