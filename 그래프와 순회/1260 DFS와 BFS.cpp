#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N, M, V;
vector<int> board[1001];
vector<int> resultDFS;
vector<int> resultBFS;
bool visited[1001];

void Input()
{
	cin >> N >> M >> V;
	for (int i = 1; i <= M; i++)
	{
		int u, v;
		cin >> u >> v;
		board[u].push_back(v);
		board[v].push_back(u);
	}
	for (int i = 1; i <= N; i++)
		sort(board[i].begin(), board[i].end());
}

void DFS(int node)
{
	resultDFS.push_back(node);
	visited[node] = true;
	for (int i = 0; i < board[node].size(); i++)
	{
		if (!visited[board[node][i]])
		{
			DFS(board[node][i]);
		}
	}
}

void BFS(int node)
{
	queue<int> q;
	q.push(node);
	visited[node] = true;
	while (!q.empty())
	{
		int x = q.front();
		resultBFS.push_back(x);
		q.pop();
		for (int i = 0; i < board[x].size(); i++)
		{
			int y = board[x][i];
			if (!visited[y])
			{
				q.push(y);
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
	DFS(V);
	for (int i = 1; i <= N; i++)
		visited[i] = 0;
	BFS(V);

	for (int i = 0; i < resultDFS.size(); i++)
		cout << resultDFS[i] << " ";
	cout << '\n';
	for (int i = 0; i < resultBFS.size(); i++)
		cout << resultBFS[i] << " ";

	return 0;
}