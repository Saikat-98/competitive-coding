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
  int temp = 1;
  w(t)
  {
    ll val, n, k, count = 0;
    cin >> n >> k;
    vector<ll> v(n);
    for (ll i = 0; i < n; i++)
    {
      cin >> val;
      v[i] = val;
    }
    for (ll i = 0; i < n;)
    {
      ll temp = k;
      if (v[i] == temp)
      {
        bool flag = true;
        for (ll j = i; j < i + k; j++, temp--)
          if (v[j] != temp)
          {
            flag = false;
            break;
          }
        if (flag == true)
        {
          count++;
          i += k;
        }
        else
          i++;
      }
      else
        i++;
    }
    cout << "Case #" << temp << ": " << count << "\n";
    temp++;
  }
  return 0;
}