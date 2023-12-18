#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<string> str;
int result = 0;

bool compare(string s1, string s2)
{
	if (s1[0] == s2[0])
	{
		return s1.size() < s2.size();
	}
	return s1 < s2;
}

void Input()
{
	cin >> N;
	string tmp;
	for (int i = 0; i < N; i++)
	{
		cin >> tmp;
		str.push_back(tmp);
	}
}

void Solve()
{
	bool isPrefix;
	sort(str.begin(), str.end(), compare);
	for (int i = 0; i < N; i++)
	{
		isPrefix = false;
		for (int j = i + 1; j < N; j++)
		{
			if (str[i] == str[j].substr(0, str[i].size()))
			{
				isPrefix = true;
				break;
			}
		}
		if (!isPrefix)
			result++;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	Input();
	Solve();

	cout << result;

	return 0;
}