#include <iostream>
#include <map>
using namespace std;

int N, M, B;
int board[500][500];
int cnt = 0;
map<int, int> result;
int sum = 0;
int height;

void Input()
{
	cin >> N >> M >> B;
	for(int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			cin >> board[i][j];
			sum += board[i][j];
		}
	height = sum / (N * M);
}

void solve()
{
	for(int k = 256; k >= 0; k--)
	{
		int block = B;
		cnt = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (k == board[i][j])
					continue;
				if (k > board[i][j])
				{
					block = block - (k - board[i][j]);
					cnt = cnt + (k - board[i][j]);
				}
				else if (k < board[i][j])
				{
					block = block + (board[i][j] - k);
					cnt = cnt + 2 * (board[i][j] - k);
				}
			}
		}
		if (block < 0)
			continue;
		else
		{
			result.insert({ cnt, k });
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	Input();
	solve();
	auto iter = result.begin();
	cout << iter->first << " " << iter->second;

	return 0;
}