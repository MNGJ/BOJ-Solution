#include <iostream>
#include <vector>
using namespace std;

int idx[201];
bool iscan = true;
int N, M;

int Find(int root)
{
	if (idx[root] == root)
		return root;
	else
		return idx[root] = Find(idx[root]);
}

void Union(int a, int b)
{
	int a_parent = Find(a);
	int b_parent = Find(b);
	if (a_parent < b_parent)
		idx[b_parent] = a_parent;
	else
		idx[a_parent] = b_parent;
}

void Input()
{
	for (int i = 0; i < 201; i++)
		idx[i] = i;
	cin >> N >> M;
	int tmp;
	for(int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
		{
			cin >> tmp;
			if (tmp == 1)
			{
				Union(i, j);
			}
		}
}

void Solve()
{
	int tmp;
	cin >> tmp;
	int root = Find(tmp);
	for (int i = 1; i < M; i++)
	{
		cin >> tmp;
		if (root != Find(tmp))
		{
			iscan = false;
			break;
		}
	}
	if (iscan)
		cout << "YES";
	else
		cout << "NO";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	Input();
	Solve();

	return 0;
}