#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
#define MAX 10001000

struct star_point 
{
	double x;
	double y;
};

struct line
{
	star_point a;
	star_point b;
	int u_point;
	int v_point;
	double value;
};

line arr[10001];
star_point point[101];
int u[101];
int n;
int cnt = 1;

bool cmp(const line& a, const line& b)
{
	return a.value < b.value;
}

int Find(int a)
{
	if (u[a] == a)
		return a;
	else
		return u[a] = Find(u[a]);
}

double Get_dist(double x, double y, double dx, double dy)
{
	return sqrt(pow(dx - x, 2) + pow(dy - y, 2));
}

void Input()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> point[i].x >> point[i].y;
	}

	for(int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			if (i == j) continue;
			arr[cnt].a = point[i];
			arr[cnt].b = point[j];
			arr[cnt].u_point = i;
			arr[cnt].v_point = j;
			arr[cnt].value = Get_dist(point[j].x, point[j].y, point[i].x, point[i].y);
			cnt++;
		}
	sort(arr + 1, arr + cnt, cmp);
	for (int i = 1; i <= n; i++)
		u[i] = i;
}

void Solve()
{
	int a, b, count = 0;
	double sum = 0;
	for (int i = 1; i < cnt; i++)
	{
		a = Find(arr[i].u_point);
		b = Find(arr[i].v_point);
		if (a != b)
		{
			if (a < b) u[b] = a;
			else u[a] = b;
			sum += arr[i].value;
			count++;
		}
		if (n - 1 == count)
			break;
	}
	cout << fixed;
	cout.precision(2);
	cout << sum;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	Input();
	Solve();

	return 0;
}