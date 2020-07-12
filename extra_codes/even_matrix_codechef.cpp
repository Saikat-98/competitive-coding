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
    int even = 2, odd = 1;
    bool is_even = false, is_odd = true;
    vector<vector<int>> v(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (is_odd)
        {
          if ((j & 1) == 0)
          {
            v[i][j] = odd;
            odd += 2;
          }
          else
          {
            v[i][j] = even;
            even += 2;
          }
        }
        if (is_even)
        {
          if ((j & 1) == 0)
          {
            v[i][j] = even;
            even += 2;
          }
          else
          {
            v[i][j] = odd;
            odd += 2;
          }
        }
      }
      is_odd = !is_odd;
      is_even = !is_even;
    }
    for (auto i : v)
    {
      for (auto j : i)
        cout << j << " ";
      cout << "\n";
    }
  }
  return 0;
}