#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int dp[1000001][2];
vector<int> Tree[1000001];
bool visited[1000001];

void Input()
{
	int a, b;
	cin >> N;
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
	dp[current_node][1] = 1; // 현재 노드 포함 o
	visited[current_node] = true;

	for (int i = 0; i < Tree[current_node].size(); i++)
	{
		int next_node = Tree[current_node][i];
		if (visited[next_node]) continue;
		DFS(next_node);
		dp[current_node][0] += dp[next_node][1];
		dp[current_node][1] += min(dp[next_node][0], dp[next_node][1]);
	}
}

void Solve()
{
	DFS(1);
	cout << min(dp[1][0], dp[1][1]);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	Input();
	Solve();

	return 0;
}