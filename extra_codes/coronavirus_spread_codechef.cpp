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
    int x, num;
    cin >> x;
    vector<int> v;
    for (int i = 0; i < x; i++)
    {
      cin >> num;
      v.emplace_back(num);
    }
    vector<int> diff(x);
    diff[0] = 0;
    for (int i = 1; i < x; i++)
      diff[i] = abs(v[i] - v[i - 1]);
    int max = INT_MIN, min = INT_MAX, count = 0;
    for (auto i : diff)
    {
      if (i <= 2)
        count++;
      else
      {
        min = std::min(min, count);
        max = std::max(max, count);
        count = 1;
      }
    }
    min = std::min(min, count);
    max = std::max(max, count);
    cout << min << " " << max << "\n";
    v.clear();
    diff.clear();
  }

  return 0;
}