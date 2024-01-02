#include <iostream>
#include <map>
#include <string>
using namespace std;

map<string, int> m; // 模备 捞抚, 模备 风飘
int test_case;
int F;
int cnt[200001];
int parent[200001];

int Find(int node)
{
	if (parent[node] == node)
		return node;
	else
		return parent[node] = Find(parent[node]);
}

int Union(int a, int b)
{
	int a_parent = Find(a);
	int b_parent = Find(b);
	if (a_parent == b_parent)
		return cnt[a_parent];

	if (a_parent < b_parent)
	{
		parent[b_parent] = a_parent;
		cnt[a_parent] += cnt[b_parent];
		return cnt[a_parent];
	}
	else
	{
		parent[a_parent] = b_parent;
		cnt[b_parent] += cnt[a_parent];
		return cnt[b_parent];
	}
}

void Input()
{
	cin >> F;
	string str1, str2;
	m.clear();
	for (int i = 0; i < 200001; i++)
	{
		cnt[i] = 1;
		parent[i] = i;
	}
	for (int i = 0; i < F; i++)
	{
		cin >> str1 >> str2;

		if (m.count(str1) == 0)
			m[str1] = m.size();
		if (m.count(str2) == 0)
			m[str2] = m.size();

		cout << Union(m[str1], m[str2]) << '\n';
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> test_case;
	while (test_case--)
	{
		Input();
	}

	return 0;
}