#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

int M, N, H;
int tomato[100][100][100];
int dx[6] = { 1, -1, 0, 0, 0, 0 };
int dy[6] = { 0, 0, 1, -1, 0, 0 };
int dz[6] = { 0, 0, 0, 0, 1, -1 };
int result = 0;

void Input()
{
	cin >> M >> N >> H;

	for(int i = 0; i < H; i++)
		for(int j = 0; j < N; j++)
			for (int k = 0; k < M; k++)
			{
				cin >> tomato[i][j][k];
			}
}

void BFS()
{
	queue<tuple<int, int, int, int>> q;
	for (int i = 0; i < H; i++)
		for (int j = 0; j < N; j++)
			for (int k = 0; k < M; k++)
			{
				if (tomato[i][j][k] == 1)
					q.push(make_tuple(i, j, k, 0));
			}
	while (!q.empty())
	{
		int z = get<0>(q.front());
		int y = get<1>(q.front());
		int x = get<2>(q.front());
		int cnt = get<3>(q.front());
		q.pop();
		for (int i = 0; i < 6; i++)
		{
			int nz = z + dz[i];
			int ny = y + dy[i];
			int nx = x + dx[i];
			result = max(result, cnt);
			if (nz < 0 || nz >= H || ny < 0 || ny >= N || nx < 0 || nx >= M || tomato[nz][ny][nx] == -1 || tomato[nz][ny][nx] == 1)
				continue;
			tomato[nz][ny][nx] = 1;
			q.push(make_tuple(nz, ny, nx, cnt+1));
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	Input();
	BFS();

	for (int i = 0; i < H; i++)
		for (int j = 0; j < N; j++)
			for (int k = 0; k < M; k++)
			{
				if (tomato[i][j][k] == 0)
				{
					cout << -1;
					return 0;
				}
			}
	cout << result;

	return 0;
}