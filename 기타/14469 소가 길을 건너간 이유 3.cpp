#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<pair<int, int>> cows;
int wating = 0;

void Input()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int t1, t2;
		cin >> t1 >> t2;
		cows.push_back(pair<int, int>(t1, t2));
	}
	sort(cows.begin(), cows.end());
}

void Solve()
{
	for (int i = 0; i < N; i++)
	{
		if (wating <= cows[i].first)
		{
			wating = cows[i].first + cows[i].second;
		}
		else
		{
			wating += cows[i].second;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	Input();
	Solve();

	cout << wating;

	return 0;
}