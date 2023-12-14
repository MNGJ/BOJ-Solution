#include <iostream>
#include <vector>
using namespace std;

int N;
int people[11];
int result[11];

void Input()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> people[i];
	}
}

void Solve()
{
	for (int i = 0; i < N; i++)
	{
		int j = 0;
		while (people[i] != 0)
		{
			if (result[j] == 0)
				people[i]--;
			j++;
		}
		while (result[j] != 0)
			j++;
		result[j] = i + 1;
	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	Input();
	Solve();
	for (int i = 0; i < N; i++)
		cout << result[i] << " ";
	return 0;
}