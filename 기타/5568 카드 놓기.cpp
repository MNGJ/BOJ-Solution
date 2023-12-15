#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n, k;
int cards[10];
vector<string> combination;
bool visited[10];

void Input()
{
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> cards[i];
	}
}

void Select(int depth, string number)
{
	if (depth == k)
	{
		combination.push_back(number);
		return;
	}
	else 
	{
		string tmp = "";
		for (int i = 0; i < n; i++)
		{
			if (visited[i])
				continue;
			tmp = to_string(cards[i]);
			visited[i] = true;
			Select(depth + 1, number + tmp);
			visited[i] = false;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	Input();
	Select(0, "");

	sort(combination.begin(), combination.end());
	combination.erase(unique(combination.begin(), combination.end()), combination.end());
	cout << combination.size();

	return 0;
}