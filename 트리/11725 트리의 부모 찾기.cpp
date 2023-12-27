#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N;
vector<int> uv[100001];
bool visited[100001];
int parent[100001];

void Input()
{
	cin >> N;
	int u, v;
	for (int i = 1; i < N; i++)
	{
		cin >> u >> v;
		uv[u].push_back(v);
		uv[v].push_back(u);
	}
}

void BFS()
{
	queue<int> q;
	q.push(1);
	visited[1] = true;
	while (!q.empty())
	{
		int p_node = q.front();
		q.pop();
		for (int i = 0; i < uv[p_node].size(); i++)
		{
			if (visited[uv[p_node][i]])
				continue;
			q.push(uv[p_node][i]);
			visited[uv[p_node][i]] = true;
			parent[uv[p_node][i]] = p_node;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	Input();
	BFS();
	for (int i = 2; i <= N; i++)
		cout << parent[i] << '\n';

	return 0;
}