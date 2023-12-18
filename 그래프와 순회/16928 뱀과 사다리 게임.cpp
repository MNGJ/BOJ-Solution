#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, M;

pair<int, int> board[101];
pair<int, int> snake[15];
pair<int, int> rope[15];
bool visited[101];
int dice[6] = { 1, 2, 3, 4 ,5, 6 };

void Input()
{
	cin >> N >> M;
	int tmp1, tmp2;
	for (int i = 1; i <= 100; i++)
		board[i] = { i, 0 };
	for(int i = 0; i < N; i++)
	{
		cin >> tmp1 >> tmp2;
		rope[i] = { tmp1, tmp2 };
	}
	for (int i = 0; i < M; i++)
	{
		cin >> tmp1 >> tmp2;
		snake[i] = { tmp1, tmp2 };
	}
}

void BFS()
{
	queue<pair<int, int>> q;
	q.push(make_pair(1, 0));
	visited[1] = true;
	while (!q.empty())
	{
		int x = q.front().first;
		int cnt = q.front().second;
		if (x == 100)
		{
			cout << cnt;
			return;
		}
		q.pop();
		for (int i = 0; i < 6; i++)
		{
			int nx = x + dice[i];
			if (nx > 100)
				continue;
			for (int i = 0; i < N; i++)
			{
				if (rope[i].first == nx)
				{
					nx = rope[i].second;
					break;
				}
			}
			for (int i = 0; i < M; i++)
			{
				if (snake[i].first == nx)
				{
					nx = snake[i].second;
					break;
				}
			}
			if (visited[nx])
				continue;
			visited[nx] = true;
			q.push(make_pair(nx, cnt + 1));
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	Input();
	BFS();

	return 0;
}