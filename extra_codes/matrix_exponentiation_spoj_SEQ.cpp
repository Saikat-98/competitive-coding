// SPOJ - SEQ code

#include <bits/stdc++.h>
#define MOD 1000000000

using namespace std;

typedef long long ll;

ll k;
vector<ll> b, c;

vector<vector<ll>> multiply(vector<vector<ll>> A, vector<vector<ll>> B)
{
  vector<vector<ll>> C(k + 1, vector<ll>(k + 1));
  for (int i = 1; i <= k; i++)
    for (int j = 1; j <= k; j++)
      for (int x = 1; x <= k; x++)
        C[i][j] = (C[i][j] + (A[i][x] * B[x][j]) % MOD) % MOD;
  return C;
}

vector<vector<ll>> pow(vector<vector<ll>> &T, ll n)
{
  if (n == 1)
    return T;
  if (n & 1)
    return multiply(T, pow(T, n - 1));
  vector<vector<ll>> v = pow(T, n / 2);
  return multiply(v, v);
}

ll calculate(ll n)
{
  if (n == 0)
    return 0;
  if (n <= k)
    return b[n - 1];
  // Step - 1 :- Make the matrix F1
  vector<ll> F1(k + 1);
  for (int i = 1; i <= k; i++)
    F1[i] = b[i - 1];
  // Step - 2 :- Transformation matrix
  vector<vector<ll>> T(k + 1, vector<ll>(k + 1));
  for (int i = 1; i <= k; i++)
    for (int j = 1; j <= k; j++)
    {
      if (i < k)
      {
        if (j == i + 1)
          T[i][j] = 1;
        else
          T[i][j] = 0;
      }
      else
        T[i][j] = c[k - j];
    }
  // Step - 3 :- T^(n-1)
  T = pow(T, n - 1);
  // Step - 4 :- Find the resulting matrix
  ll res = 0;
  for (int i = 1; i <= k; i++)
    res = (res + (T[1][i] * F1[i]) % MOD) % MOD;
  return res;
}

int main()
{
  ll t;
  cin >> t;
  while (t--)
  {
    ll num, n;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
      cin >> num;
      b.emplace_back(num);
    }
    for (int i = 0; i < k; i++)
    {
      cin >> num;
      c.emplace_back(num);
    }
    cin >> n;
    cout << calculate(n) << "\n";
    b.clear();
    c.clear();
  }
  return 0;
}