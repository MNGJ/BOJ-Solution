#include <iostream>
#include <vector>
using namespace std;

int N;
vector<char> uv[27];

void Input()
{
	cin >> N;
	char node, left, right;
	for (int i = 0; i < N; i++)
	{
		cin >> node >> left >> right;
		uv[node - 'A'].push_back(left);
		uv[node - 'A'].push_back(right);
	}
}

void DFS1(char node)
{
	if (node == '.')
		return;
	char left = uv[node - 'A'][0];
	char right = uv[node - 'A'][1];
	cout << node;
	DFS1(left);
	DFS1(right);
}

void DFS2(char node)
{
	if (node == '.')
		return;
	char left = uv[node - 'A'][0];
	char right = uv[node - 'A'][1];
	DFS2(left);
	cout << node;
	DFS2(right);
}

void DFS3(char node)
{
	if (node == '.')
		return;
	char left = uv[node - 'A'][0];
	char right = uv[node - 'A'][1];
	DFS3(left);
	DFS3(right);
	cout << node;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	Input();
	DFS1('A');
	cout << '\n';
	DFS2('A');
	cout << '\n';
	DFS3('A');

	return 0;
}