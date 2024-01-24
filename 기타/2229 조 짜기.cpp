#include <iostream>
using namespace std;

int N;
int arr[1001], s[1001];
int mx, mn;

void Input()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	Input();

	for (int i = 0; i < N; i++)
	{
		mx = mn = arr[i];
		for (int j = i; j >= 0; j--)
		{
			mx = max(mx, arr[j]);
			mn = min(mn, arr[j]);
			s[i + 1] = max(s[i + 1], s[j] + mx - mn);
		}
	}

	cout << s[N];

	return 0;
}