#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string.h>
#include <string>
using namespace std;
#define MAX 10000

int test_case;
int A, B;
int minimum[MAX];

void BFS()
{
	queue<pair<int, string>> q;
	q.push({A, ""});
	minimum[A] = 0;
	while (!q.empty())
	{
		int num = q.front().first;
		string sequence = q.front().second;
		q.pop();
		if (num == B)
		{
			cout << sequence << '\n';
			return;
		}
		// D Cal
		int tmp = (num * 2) % MAX;
		if(minimum[tmp] == -1)
		{
			minimum[tmp] = minimum[num] + 1;
			q.push({tmp, sequence + "D" });
		}
		// S Cal
		tmp = num - 1;
		if (tmp == -1) tmp = 9999;
		if (minimum[tmp] == -1)
		{
			minimum[tmp] = minimum[num] + 1;
			q.push({tmp, sequence + "S"});
		}
		// L cal
		tmp = (num % 1000) * 10 + (num / 1000);
		if (minimum[tmp] == -1)
		{
			minimum[tmp] = minimum[num] + 1;
			q.push({tmp, sequence + "L"});
		}
		// R cal
		tmp = num / 10 + (num % 10) * 1000;
		if (minimum[tmp] == -1)
		{
			minimum[tmp] = minimum[num] + 1;
			q.push({tmp, sequence + "R"});
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> test_case;

	while (test_case--)
	{
		cin >> A >> B;
		memset(minimum, -1, sizeof(minimum));
		BFS();
	}

	return 0;
}