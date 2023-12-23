#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int arr[1001];
int DP[1001];
vector<int> LIS[1001];
vector<int> ans;

void Input()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> arr[i];
}

void Solve()
{
	for (int i = 1; i <= N; i++)
	{
		DP[i] = 1;
		LIS[i].push_back(arr[i]);
		for (int j = 1; j < i; j++)
		{
			if (arr[i] > arr[j])
			{
				if (DP[i] < DP[j] + 1)
				{
					LIS[i].clear();
					LIS[i] = LIS[j];
					LIS[i].push_back(arr[i]);
					DP[i] = DP[j] + 1;
				}
			}
		}
		if (ans.size() < LIS[i].size())
			ans = LIS[i];
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	Input();
	Solve();

	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";

	return 0;
}