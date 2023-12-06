#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int N, M, R;
vector<int> board[100001];
bool visited[100001];
int result[100001];
int cnt = 0;

void Input()
{
	cin >> N >> M >> R;
	int u, v;
	for (int i = 1; i <= M; i++)
	{
		cin >> u >> v;
		board[u].push_back(v);
		board[v].push_back(u);
	}
	for (int i = 1; i <= N; i++)
		sort(board[i].begin(), board[i].end(), greater<>());
}

void BFS(int node)
{
	queue<int> q;
	q.push(node);
	cnt++;
	result[node] = cnt;
	visited[node] = true;
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		for (int i = 0; i < board[x].size(); i++)
		{
			int y = board[x][i];
			if (!visited[y])
			{
				q.push(y);
				cnt++;
				result[y] = cnt;
				visited[y] = true;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	Input();
	BFS(R);

	for (int i = 1; i <= N; i++)
		cout << result[i] << '\n';

	return 0;
}