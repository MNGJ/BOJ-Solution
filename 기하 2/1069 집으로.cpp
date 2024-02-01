#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

double X, Y, D, T, ans;

void Solve()
{
	cout << fixed;
	cout.precision(9);
	double d = sqrt(X * X + Y * Y);
	if (T >= D)
	{
		cout << d;
		return;
	}
	else
	{
		ans = d;

		int jump = d / D; // 점프 횟수
		d -= jump * D; // 남은 거리

		if (jump == 0) ans = min(ans, min(T + D - d, 2.0 * T));
		else ans = min(ans, min(jump * T + d, (jump + 1.0) * T));

		cout << ans;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> X >> Y >> D >> T;
	Solve();

	return 0;
}