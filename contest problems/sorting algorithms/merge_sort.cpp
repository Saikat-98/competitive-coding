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

void merge(int arr[], int start, int end, int size)
{
  int mid = (start + end) / 2;
  int i = start, j = mid + 1, k = start;
  int temp[size];

  while (i <= mid && j <= end)
  {
    if (arr[i] < arr[j])
      temp[k++] = arr[i++];
    else
      temp[k++] = arr[j++];
  }
  while (i <= mid)
    temp[k++] = arr[i++];
  while (j <= end)
    temp[k++] = arr[j++];

  for (int i = start; i <= end; i++)
    arr[i] = temp[i];
}

void mergeSort(int arr[], int start, int end, int size)
{
  if (start >= end)
    return;

  int mid = (start + end) / 2;

  mergeSort(arr, start, mid, size);
  mergeSort(arr, mid + 1, end, size);

  merge(arr, start, end, size);
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
  mergeSort(arr, 0, n - 1, n);
  for (auto i : arr)
    cout << i << " ";
  return 0;
}