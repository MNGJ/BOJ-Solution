#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAX 21

int N, len;
int seq[MAX];
int DP[MAX][MAX][MAX];

int go(int index, int op1, int op2)
{
	if (index == len + 1) // 마지막 순서를 벗어나는 경우
		return 0;
	if (DP[index][op1][op2] != -1) // 이미 값이 있는경우
		return DP[index][op1][op2];

	int nextBlock = seq[index];
	DP[index][op1][op2] = min(abs(op1 - nextBlock) + go(index + 1, nextBlock, op2), abs(op2 - nextBlock) + go(index + 1, op1, nextBlock));
	return DP[index][op1][op2];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int open1, open2;
	cin >> N;
	cin >> open1 >> open2;

	cin >> len;
	for (int i = 1; i <= len; i++)
	{
		int num;
		cin >> num;
		seq[i] = num;
	}

	memset(DP, -1, sizeof(DP));
	cout << go(1, open1, open2);

	return 0;
}