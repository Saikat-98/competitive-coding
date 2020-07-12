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

int partition(int arr[], int start, int end)
{
	int i = start - 1;
	int j = start;
	int pivot = arr[end];
	while (j < end)
	{
		if (arr[j] <= pivot)
		{
			i++;
			swap(arr[j], arr[i]);
		}
		j++;
	}
	swap(arr[end], arr[i + 1]);
	return i + 1;
}

void quicksort(int arr[], int start, int end)
{
	if (start >= end)
		return;
	int p = partition(arr, start, end);
	quicksort(arr, start, p - 1);
	quicksort(arr, p + 1, end);
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
	quicksort(arr, 0, n - 1);
	for (auto i : arr)
		cout << i << " ";
	return 0;
}