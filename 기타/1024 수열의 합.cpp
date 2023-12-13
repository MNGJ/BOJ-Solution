#include <iostream>
#include <vector>
using namespace std;

int N, L, cnt;
bool flag = false;
vector<int> result;

void Input()
{
	cin >> N >> L;
}

void Solve()
{
	while (L <= 100)
	{
		int sum = 0;
		for (int i = 0; i < L; i++)
		{
			sum += i;
		}
		if (sum > N)
			break;
		cnt = 0;
		while (sum <= N)
		{
			if (sum == N)
			{
				flag = true;
				break;
			}
			cnt++;
			sum += L;
		}
		if (flag == true)
		{
			break;
		}
		L++;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	Input();
	Solve();
	if (flag == false)
		cout << -1 << '\n';
	else
		for (int i = cnt; i < cnt + L; i++)
			cout << i << " ";

	return 0;
}