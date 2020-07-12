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
    ll x, y, l, r;
    cin >> x >> y >> l >> r;
    vector<int> v1;
    vector<int> v2;

    for (int j = 0; j < 64; j++)
      if ((1 << j) & x)
        for (int i = l; i <= r; i++)
          if ((1 << j) & i && find(v2.begin(), v2.end(), i) == v2.end())
            v2.emplace_back(i);

    for (int j = 0; j < 64; j++)
      if ((1 << j) & y)
        for (int i = l; i <= r; i++)
          if ((1 << j) & i && find(v1.begin(), v1.end(), i) == v1.end())
            v1.emplace_back(i);

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    // for (auto i : v1)
    //   cout << i << " ";
    // cout << "\n";
    // for (auto i : v2)
    //   cout << i << " ";

    if (v1.size() > v2.size())
    {
      for (int i = v2.size() - 1; i >= 0; i--)
        if (binary_search(v1.begin(), v1.end(), v2[i]))
        {
          cout << v2[i] << "\n";
          break;
        }
    }
    else
    {
      for (int i = v1.size() - 1; i >= 0; i--)
        if (binary_search(v2.begin(), v2.end(), v1[i]))
        {
          cout << v1[i] << "\n";
          break;
        }
    }
  }
  return 0;
}