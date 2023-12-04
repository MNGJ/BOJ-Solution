#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int N;
double ans = 0;
vector <pair<int, int>> board;

void Input()
{
	cin >> N;
	int x, y;
	for (int i = 0; i < N; i++)
	{
		cin >> x >> y;
		board.push_back(make_pair(x, y));
	}
}

void Solve()
{
	double a, b, c, s, S;
	int x1, y1, x2, y2, x3, y3;
	for (int i = 0; i < N; i++)
	{
		x1 = board[i].first;
		y1 = board[i].second;
		for (int j = 0; j < N; j++)
		{
			if (i == j)
				continue;
			x2 = board[j].first;
			y2 = board[j].second;
			for (int k = 0; k < N; k++)
			{
				if (k == j || k == i)
					continue;
				x3 = board[k].first;
				y3 = board[k].second;
				a = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
				b = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
				c = sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2));
				s = (a + b + c) / 2;
				S = sqrt(s * (s - a) * (s - b) * (s - c));
				ans = max(ans, S);
				
			}
		}
	}
	cout << ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	Input();
	Solve();

	return 0;
}