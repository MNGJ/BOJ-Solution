#include <iostream>
#include <vector>
using namespace std;

int N;
int arr[1000001];
int index_arr[1000001];
vector<int> v;

void Input()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}
}

void Solve()
{
	for (int i = 1; i <= N; i++)
	{
		if (v.size() == 0 || v[v.size() - 1] < arr[i])
		{
			v.push_back(arr[i]);
			index_arr[i] = v.size() - 1;
		}
		else
		{
			int left = 0;
			int right = v.size() - 1;
			while (left < right)
			{
				int mid = (left + right) / 2;

				if (v[mid] >= arr[i]) right = mid;
				else left = mid + 1;
			}
			v[left] = arr[i];
			index_arr[i] = left;
		}
	}
	cout << v.size() << '\n';
	vector<int> ans;
	int find_index = v.size() - 1;
	for (int i = N; i > 0; i--)
	{
		if (index_arr[i] == find_index)
		{
			find_index--;
			ans.push_back(arr[i]);
		}
	}
	for (int i = ans.size() - 1; i >= 0; i--) 
		cout << ans[i] << " ";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	Input();
	Solve();

	return 0;
}