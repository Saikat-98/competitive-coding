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
  w(t)
  {
    int n;
    cin >> n;
    vector<int> vx;
    vector<int> vy;
    for (int i = 0; i < 4 * n - 1; i++)
    {
      int x, y;
      cin >> x >> y;
      vx.emplace_back(x);
      vy.emplace_back(y);
    }

    int x = 0, y = 0;
    for (auto i : vx)
      x ^= i;
    for (auto i : vy)
      y ^= i;
    cout << x << " " << y << "\n";
  }
  return 0;
}