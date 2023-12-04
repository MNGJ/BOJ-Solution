#include <iostream>
#include <string>
using namespace std;

int N, M, R;

int V_set[100001];
int E_set[200001];
bool visited[200001];

void DFS(int V, int E, int R) // V : 정점 집합, E : 간선 집합, R : 시작 정점
{
	visited[R] = true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> R;

	for (int i = 0; i < M; i++)
	{

	}

	return 0;
}