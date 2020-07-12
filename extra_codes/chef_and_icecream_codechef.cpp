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
    int n, val;
    cin >> n;
    cin >> val;
    bool flag = true;
    if (val != 5)
      flag = false;
    unordered_map<int, int> m;
    m[5] = 0;
    m[10] = 0;
    m[15] = 0;

    int sum = 5;
    m[val]++;
    for (int i = 1; i < n; i++)
    {
      cin >> val;
      int leftAmt = val - 5;
      
      m[val]++;
      while (leftAmt > 0)
      {
        if (m[leftAmt] != 0)
        {
          m[leftAmt]--;
          break;
        }
        if (m[leftAmt - 5] != 0)
        {
          m[leftAmt - 5]--;
          leftAmt -= 5;
        }
        else
        {
          flag = false;
          break;
        }
      }
    }
    if (flag)
      cout << "YES"
           << "\n";
    else
      cout << "NO"
           << "\n";
  }
  return 0;
}