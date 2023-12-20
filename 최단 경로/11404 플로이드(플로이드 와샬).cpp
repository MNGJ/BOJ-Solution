#include <iostream>
#include <algorithm>
using namespace std;

//플로이드 - 와샬은 정점과 정점사이의 모든 쌍에 대한 최단경로를 찾을때 쓰임
//			거쳐가는 정점을 이용해서 다이나믹 프로그래밍과 유사한 구조를 지님
//			2차원 배열로 i j에 대해 i에서 j로 갈때의 최단 경로를 갱신해줌. i-j와 i-k-j로 갈때 더 짧은거리
const long long INF = 1e9;
int n, m;
long long NN[101][101];

void Input()
{
	for (int i = 0; i < 101; i++)
		for (int j = 0; j < 101; j++)
		{
			if (i == j)
				NN[i][j] = 0;
			else
				NN[i][j] = INF;
		}
	cin >> n >> m;
	int a, b, c;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		if (NN[a][b] > c)
			NN[a][b] = c;
	}
}

void floydWarshall()
{
	int d[101][101];

	for (int i = 0; i < 101; i++)
		for (int j = 0; j < 101; j++)
			d[i][j] = NN[i][j];

	//k = 거쳐가는 노드
	for(int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++) // i = 시작 노드
			for (int j = 1; j <= n; j++) // j = 도착 노드
			{
				if (d[i][j] > d[i][k] + d[k][j])
					d[i][j] = d[i][k] + d[k][j];
			}

	for(int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (d[i][j] == INF)
				cout << 0 << " ";
			else
				cout << d[i][j] << " ";
		}
		cout << '\n';
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	Input();
	floydWarshall();

	return 0;
}