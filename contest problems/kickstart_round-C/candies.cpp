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

vector<pair<ll, ll>> makePair(vector<ll> v, ll size)
{
  vector<pair<ll, ll>> v1;
  for (ll i = 0; i < size; i++)
  {
    ll ans = 0, ans1 = 0;
    for (ll j = i, k = 1; j < size; j++, k++)
    {
      if (k & 1)
      {
        ans += v[j] * k;
        ans1 += v[j];
      }
      else
      {
        ans -= v[j] * k;
        ans1 -= v[j];
      }
    }
    v1.emplace_back(make_pair(ans, ans1));
  }
  return v1;
}

int main()
{
  fastIO();
  int temp = 1;
  w(t)
  {
    ll n, q, val;
    cin >> n >> q;
    vector<ll> v(n);
    for (ll i = 0; i < n; i++)
    {
      cin >> val;
      v[i] = val;
    }
    vector<pair<ll, ll>> values = makePair(v, n);
    ll count = 0;
    for (ll i = 0; i < q; i++)
    {
      char ch;
      ll l, r, ans = 0;
      cin >> ch >> l >> r;
      if (ch == 'Q')
      {
        ll ans = 0;
        ans += values[l - 1].first;
        if ((r - l + 1) & 1)
          ans += ((r - l + 1) * values[r].second) + values[r].first;
        else
          ans -= ((r - l + 1) * values[r].second) + values[r].first;
        count += ans;
      }
      else
      {
        v[l - 1] = r;
        values = makePair(v, n);
      }
    }
    cout << "Case #" << temp << ": " << count << "\n";
    temp++;
  }
  return 0;
}