#include <iostream>
#include <vector>
using namespace std;

int tree[10001];
int cnt, n;

void postOrder(int cur_node, int end)
{
	if (cur_node >= end) return;
	int mid = cur_node + 1;

	while (tree[cur_node] > tree[mid] && mid < end) mid++;

	postOrder(cur_node + 1, mid);
	postOrder(mid, end);

	cout << tree[cur_node] << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while (cin >> n) tree[++cnt] = n;
	postOrder(1, cnt + 1);

	return 0;
}