#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX = 2147483648

struct Info
{
	int a;
	int b;
	int dis;
};

bool cmp(const Info& a, const Info& b)
{
	return a.dis < b.dis;
}

int m, n;
int u[200001];

int Find(int a)
{
	if (u[a] == a)
		return a;
	else
		return u[a] = Find(u[a]);
}

void Union(int a, int b)
{
	a = Find(a);
	b = Find(b);
	if (a < b)
		u[b] = a;
	else
		u[a] = b;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> m >> n;
	while (m != 0 && n != 0)
	{
		int x, y, z;
		int sum = 0;
		int save = 0;
		vector<Info> arr;
		for (int i = 0; i < n; i++)
		{
			cin >> x >> y >> z;
			arr.push_back({ x, y, z });
			u[i] = i;
			sum += z;
		}
		sort(arr.begin(), arr.end(), cmp);
		for (int i = 0; i < arr.size(); i++)
		{
			x = Find(arr[i].a);
			y = Find(arr[i].b);
			if (x != y)
			{
				Union(x, y);
				save += arr[i].dis;
			}
		}
		cout << sum-save << '\n';
		cin >> m >> n;
	}

	return 0;
}