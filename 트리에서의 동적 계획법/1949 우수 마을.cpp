#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int dp[10001][2];
vector<int> Town[10001];
int w[10001];
bool visited[10001];

void Input()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> w[i];
	int a, b;
	for (int i = 1; i < N; i++)
	{
		cin >> a >> b;
		Town[a].push_back(b);
		Town[b].push_back(a);
	}
}

void DFS(int current_node)
{
	dp[current_node][0] = 0; // 현재 노드가 우수마을이 아닐 경우
	dp[current_node][1] = w[current_node]; // 현재 노드가 우수마을 일 경우
	visited[current_node] = true;

	for (int i = 0; i < Town[current_node].size(); i++)
	{
		int next_node = Town[current_node][i];
		if (visited[next_node]) continue;
		DFS(next_node);
		dp[current_node][0] += max(dp[next_node][0], dp[next_node][1]);
		dp[current_node][1] += dp[next_node][0];
	}
}

void Solve()
{
	DFS(1);
	cout << max(dp[1][1], dp[1][0]);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	Input();
	Solve();

	return 0;
}