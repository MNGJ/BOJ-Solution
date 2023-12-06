#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int cnt = 0;
vector<int> board[101];
bool visited[101];

void Input()
{
	cin >> N >> M;
	for (int i = 1; i <= M; i++)
	{
		int u, v;
		cin >> u >> v;
		board[u].push_back(v);
		board[v].push_back(u);
	}
}

void DPS(int node)
{
	if (visited[node])
		return;
	visited[node] = true;
	cnt++;
	for (int i = 0; i < board[node].size(); i++)
	{
		DPS(board[node][i]);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	Input();
	DPS(1);

	cout << cnt-1;

	return 0;
}