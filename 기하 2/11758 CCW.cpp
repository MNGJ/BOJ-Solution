#include <iostream>
using namespace std;

int x_1;
int y_1;
int x_2;
int y_2;
int x_3;
int y_3;

int CCW(int xx1, int yy1, int xx2, int yy2, int xx3, int yy3)
{
	return (xx2 - xx1) * (yy3 - yy1) - (xx3 - xx1) * (yy2 - yy1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> x_1 >> y_1 >> x_2 >> y_2 >> x_3 >> y_3;
	int ccw = CCW(x_1, y_1, x_2, y_2, x_3, y_3);
	if (ccw >= 1)
		cout << 1;
	else if (ccw == 0)
		cout << 0;
	else
		cout << -1;

	return 0;
}