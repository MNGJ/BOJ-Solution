#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int w[10001];
int dp[10001][2];
int N;
bool visited[10001];
vector<int> Tree[10001];
vector<int> Path;

void Input()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> w[i];
	}
	int a, b;
	for (int i = 1; i < N; i++)
	{
		cin >> a >> b;
		Tree[a].push_back(b);
		Tree[b].push_back(a);
	}
}

void DFS(int current_node)
{
	dp[current_node][0] = 0; // 현재 노드 포함 x
	dp[current_node][1] = w[current_node]; // 현재 노드 포함 o

	visited[current_node] = true;

	for (int i = 0; i < Tree[current_node].size(); i++)
	{
		int next_node = Tree[current_node][i];
		if (visited[next_node]) continue;

		DFS(next_node);
		dp[current_node][0] += max(dp[next_node][0], dp[next_node][1]);
		dp[current_node][1] += dp[next_node][0];
	}
}

void tracing(int current_node, int prev_node)
{
	if (dp[current_node][1] > dp[current_node][0] && !visited[prev_node])
	{
		Path.push_back(current_node);
		visited[current_node] = true;
	}
	for (int i = 0; i < Tree[current_node].size(); i++)
	{
		int next_node = Tree[current_node][i];
		if (next_node == prev_node) continue;
		tracing(next_node, current_node);
	}
}

void Solve()
{
	DFS(1);
	memset(visited, 0, sizeof(visited));
	tracing(1, 0);
	sort(Path.begin(), Path.end());

	cout << max(dp[1][0], dp[1][1]) << '\n';
	for (auto i : Path)
		cout << i << " ";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	Input();
	Solve();

	return 0;
}