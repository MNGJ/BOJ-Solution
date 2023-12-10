#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int board[502][502];
bool visited[502][502];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int result_max = 0;

void DFS(int y, int x, int depth, int val)
{
	if (depth == 4)
	{
		result_max = max(result_max, val);
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 1 || ny > N || nx < 1 || nx > M || visited[ny][nx])
			continue;
		visited[ny][nx] = true;
		DFS(ny, nx, depth + 1, val + board[ny][nx]);
		visited[ny][nx] = false;
	}
}

void Input()
{
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			cin >> board[i][j];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	Input();
	for(int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
		{
			visited[i][j] = true;
			DFS(i, j, 1, board[i][j]);
			visited[i][j] = false;
		}
	for(int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
		{
			int t = board[i][j];
			int min_t = 1001;
			for (int k = 0; k < 4; k++)
			{
				min_t = min(min_t, board[i + dy[k]][j + dx[k]]);
				t += board[i + dy[k]][j + dx[k]];
			}
			result_max = max(result_max, t - min_t);
		}

	cout << result_max;

	return 0;
}