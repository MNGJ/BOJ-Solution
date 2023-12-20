#include <iostream>
#include <algorithm>
using namespace std;

//�÷��̵� - �ͼ��� ������ ���������� ��� �ֿ� ���� �ִܰ�θ� ã���� ����
//			���İ��� ������ �̿��ؼ� ���̳��� ���α׷��ְ� ������ ������ ����
//			2���� �迭�� i j�� ���� i���� j�� ������ �ִ� ��θ� ��������. i-j�� i-k-j�� ���� �� ª���Ÿ�
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

	//k = ���İ��� ���
	for(int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++) // i = ���� ���
			for (int j = 1; j <= n; j++) // j = ���� ���
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