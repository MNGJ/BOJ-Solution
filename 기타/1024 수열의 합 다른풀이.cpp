#include <iostream>
using namespace std;

int N, L;
int cnt;

void Input()
{
	cin >> N >> L;
}

void Solve()
{
	for (int i = 0; i < L; i++)
		cnt += i;
	for (int i = L; i <= 100; i++)
	{
		if (N >= cnt && (N-cnt) % i == 0)
		{
			for (int j = 0; j < i; j++)
			{
				cout << (N - cnt) / i + j << " ";
			}
			return;
		}
		cnt += i;
	}
	cout << -1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	Input();
	Solve();

	return 0;
}