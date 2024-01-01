#include <iostream>
#include <cmath>
using namespace std;

const double ALLOW = 0.0001;
double x, y, c;

void Input()
{
	cin >> x >> y >> c;
}

double func(double mid)
{
	double h1 = sqrt(x * x - mid * mid);
	double h2 = sqrt(y * y - mid * mid);
	double c_ = (h1 * h2) / (h1 + h2);
	return c_;
}

void Solve()
{
	double low = 0;
	double high = min(x, y);
	double result = 0;

	while (high - low > ALLOW)
	{
		double mid = (low + high) / 2.0;

		if (func(mid) >= c)
		{
			result = mid;
			low = mid;
		}
		else
			high = mid;
	}
	cout.precision(5);
	cout << result;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	Input();
	Solve();

	return 0;
}