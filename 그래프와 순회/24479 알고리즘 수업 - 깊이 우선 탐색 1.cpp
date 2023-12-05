#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M, R;

vector<int> board[100001];
int result[100001];
bool visited[100001];
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
		sort(board[i].begin(), board[i].end());
}

void DFS(int node)
{
	if (visited[node])
		return;

	visited[node] = true;
	cnt++;
	result[node] = cnt;
	for (int x = 0; x < board[node].size(); x++)
	{
		DFS(board[node][x]);
	}
}

void solve()
{
	for (int i = 1; i <= N; i++)
		cout << result[i] << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Input();
	DFS(R);
	solve();

	return 0;
}