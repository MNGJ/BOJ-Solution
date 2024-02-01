#include <iostream>
#include <math.h>
using namespace std;

#define PI 3.14159265359
double X1, Y1, r1, X2, Y2, r2;
double S = 0;

void Solve()
{
	cout << fixed;
	cout.precision(3);
	double d = sqrt(pow(X2-X1, 2) + pow(Y2 - Y1, 2));
	if (d > r1 + r2)
	{
		cout << 0.000;
		return;
	}
	else if (d <= abs(r1 - r2))
	{
		S = PI * pow(min(r1, r2), 2);
		cout << S;
		return;
	}
	else
	{
		double t1 = 2.0 * acos((d * d + r1 * r1 - r2 * r2) / (2.0 * d * r1));
		double t2 = 2.0 * acos((d * d + r2 * r2 - r1 * r1) / (2.0 * d * r2));

		S = 0.5 * (t1 * r1 * r1 + t2 * r2 * r2 - r1 * r1 * sin(t1) - r2 * r2 * sin(t2));
		cout << S;
		return;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> X1 >> Y1 >> r1 >> X2 >> Y2 >> r2;
	Solve();

	return 0;
}