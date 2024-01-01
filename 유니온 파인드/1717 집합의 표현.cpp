#include <iostream>
using namespace std;

int n, m;
int idx[1000001];
int Find(int a)
{
	if (idx[a] == a)
		return a;
	else
		return idx[a] = Find(idx[a]);
}

void uni(int a, int b)
{
	int a_parent = Find(a);
	int b_parent = Find(b);
	if (a_parent < b_parent)
		idx[b_parent] = a_parent;
	else
		idx[a_parent] = b_parent;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i <= n; i++)
		idx[i] = i;
	int cal, a, b;
	while (m--)
	{
		cin >> cal >> a >> b;
		if (cal == 0)
		{
			uni(a, b);
		}
		else
		{
			int tmp1, tmp2;
			tmp1 = Find(a);
			tmp2 = Find(b);
			if (tmp1 == tmp2)
				cout << "YES" << '\n';
			else
				cout << "NO" << '\n';
		}
	}
	for (int i = 0; i <= n; i++)
		cout << idx[i] << " ";

	return 0;
}