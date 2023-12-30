#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 5005;

int n, m;
int arr[101][101];
int ans = MAX;
int idx = 0;
void Input()
{
	for (int i = 0; i < 101; i++)
		for (int j = 0; j < 101; j++)
			arr[i][j] = MAX;
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int x, y;
		cin >> x >> y;
		arr[x][y] = 1;
		arr[y][x] = 1;
	}
}

void Floyd_Warshall()
{
	for(int K = 1; K <= n; K++)
		for(int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
			{
				if (K == i || i == j || j == K)
					continue;
				if (arr[i][j] > arr[i][K] + arr[K][j])
					arr[i][j] = arr[i][K] + arr[K][j];
			}
	
	for(int i = 1; i <= n; i++)
	{
		int sum = 0;
		for (int j = 1; j <= n; j++)
		{
			if (i == j)
				continue;
			sum += arr[i][j];
		}
		if (ans > sum)
		{
			ans = sum;
			idx = i;
		}
	}
	cout << idx;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	Input();
	Floyd_Warshall();

	return 0;
}