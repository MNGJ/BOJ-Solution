#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int N;
vector<pair<long long, long long>> cools;

double Get_distance(long long x, long long y, long long xx, long long yy)
{
	return sqrt(pow(x - xx, 2) + pow(y - yy, 2));
}

double Heron(double a, double b, double c)
{
	double s = (a + b + c) / 2;
	return sqrt(s * (s - a) * (s - b) * (s - c));
}

void Input()
{
	cin >> N;
	long long x, y;
	for (int i = 1; i <= N; i++)
	{
		cin >> x >> y;
		cools.push_back({ x, y });
	}
}

long long ccw(long long x1, long long y1, long long x2, long long y2, long long x3, long long y3)
{
	return x1 * y2 + x2 * y3 + x3 * y1 - (x2 * y1 + x3 * y2 + x1 * y3);
}

void Solve()
{
	double sum = 0;
	long long x1 = cools[0].first;
	long long y1 = cools[0].second;
	for (int i = 1; i < cools.size() - 1; i++)
	{
		long long x2 = cools[i].first;
		long long y2 = cools[i].second;
		long long x3 = cools[i+1].first;
		long long y3 = cools[i+1].second;
		double a = Get_distance(x1, y1, x2, y2);
		double b = Get_distance(x2, y2, x3, y3);
		double c = Get_distance(x1, y1, x3, y3);
		double S = Heron(a, b, c);
		if (ccw(x1, y1, x2, y2, x3, y3) > 0)
			sum -= S;
		else
			sum += S;
	}
	cout << fixed;
	cout.precision(1);
	cout << abs(sum);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	Input();
	Solve();

	return 0;
}