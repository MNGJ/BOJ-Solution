#include <iostream>
#include <string>
using namespace std;

int N, M;
string S;
int cnt = 0;

void Input()
{
	cin >> N >> M;
	cin >> S;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	Input();

	for (int i = 0; i < M; i++)
	{
		int k = 0;
		if (S[i] == 'O')
			continue;
		else
		{
			while (S[i + 1] == 'O' && S[i + 2] == 'I')
			{
				k++;
				if (k == N)
				{
					k--;
					cnt++;
				}
				i += 2;
			}
		}
	}

	cout << cnt;

	return 0;
}