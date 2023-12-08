#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int board[50][50];
bool visited[50][50];
int dx[4] = {1, -1, 0, 0};
int dy[4] = { 0, 0, 1, -1 };
int test_case, M, N, K;
vector<int> result;

void Input()
{
	cin >> M >> N >> K;
	for (int i = 0; i < K; i++)
	{
		int x, y;
		cin >> x >> y;
		board[y][x] = 1;
	}
}

void DFS(int y, int x)
{
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= M || ny < 0 || ny >= N)
			continue;
		if (board[ny][nx] == 0 || visited[ny][nx])
			continue;
		visited[ny][nx] = true;
		K--;
		DFS(ny, nx);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> test_case;
	while (test_case--)
	{
		Input();
		for(int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
			{
				if (board[i][j] == 1 && !visited[i][j])
				{
					visited[i][j] = true;
					DFS(i, j);
				}
			}
		result.push_back(K);
		for(int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
			{
				board[i][j] = 0;
				visited[i][j] = false;
			}
	}

	for (auto i : result)
		cout << i << '\n';

	return 0;
}