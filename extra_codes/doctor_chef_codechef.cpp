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
    long n, x, val, count = 0, tempCount = 0;
    cin >> n >> x;
    vector<long> v;
    for (int i = 0; i < n; i++)
    {
      cin >> val;
      v.emplace_back(val);
    }
    sort(v.begin(), v.end());
    vector<long> completed;

    while (completed.size() < n - 1)
    {
      auto itr = upper_bound(v.begin() + tempCount, v.end(), x);
      int pos = itr - v.begin();
      tempCount += pos;
      if (pos > 0)
      {
        int temp = pos;
        while (temp--)
        {
          completed.emplace_back(temp);
          v[temp] = 0;
          count++;
        }
        count--;
        x = v[pos] << 1;
      }
      else
        x <<= 1;
      count++;
    }
    // cout << v[n - 1] << " " << x;
    if (x >= v[n - 1])
      cout << count << "\n";
    // else
    // {
    //   long temp = v[n - 1];
    //   while (x < temp)
    //   {
    //     x <<= 1;
    //     count++;
    //   }
    //   cout << count << "\n";
    // }
  }
  return 0;
}