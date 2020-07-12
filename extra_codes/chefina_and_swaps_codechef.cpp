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
    long n, val, count = 0, min1 = INT_MAX;
    cin >> n;
    map<long, long> m1, m2, m;
    for (long i = 0; i < n; i++)
    {
      cin >> val;
      min1 = min(min1, val);
      if (m1[val])
        m1[val]++;
      else
        m1[val] = 1;
    }
    for (long i = 0; i < n; i++)
    {
      cin >> val;
      min1 = min(min1, val);
      if (m2[val])
        m2[val]++;
      else
        m2[val] = 1;
    }

    bool flag = false;
    for (auto i : m1)
      if ((i.second + m2[i.first]) & 1)
      {
        flag = true;
        break;
      }
    for (auto i : m2)
      if ((i.second + m1[i.first]) & 1)
      {
        flag = true;
        break;
      }
    if(flag){
      cout << "-1"
             << "\n";
      continue;
    }
    if (!flag)
    {
      vector<long> v;
      for (auto i : m1)
        if (i.second > m2[i.first])
        {
          int times = (i.second - m2[i.first]) / 2;
          while (times--)
            v.emplace_back(i.first);
        }
      for (auto i : m2)
        if (i.second > m1[i.first])
        {
          int times = (i.second - m1[i.first]) / 2;
          while (times--)
            v.emplace_back(i.first);
        }

      sort(v.begin(), v.end());
      for (long i = 0; i < v.size() / 2; i++)
        count += min(v[i], 2 * min1);
      cout << count << "\n";
    }
  }
  return 0;
}