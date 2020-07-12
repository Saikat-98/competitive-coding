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
  int n, val;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++)
  {
    cin >> val;
    arr[i] = val;
  }

  for (int i = 0; i < n; i++)
  {
    int e = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > e)
    {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = e;
  }

  for (auto i : arr)
    cout << i << " ";
  return 0;
}