#include <iostream>
#include <vector>
using namespace std;

int N;
int index[100001];
int inorder[100001];
int postorder[100001];

void Input()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> inorder[i];
		index[inorder[i]] = i; // inorder ��ҵ��� index ���� ����
	}
	for (int i = 1; i <= N; i++)
		cin >> postorder[i];
}

void getPreOrder(int inStart, int inEnd, int postStart, int postEnd)
{
	if (inStart > inEnd || postStart > postEnd) // �� �̻� ���� �� �� ���� ���
		return;
	// postorder�� �� ���� root ��
	// index �迭�� ���� inorder ������ root index�� ���� ���� �� �ִ�.
	int rootIndex = index[postorder[postEnd]];
	int leftSize = rootIndex - inStart;
	int rightSize = inEnd - rootIndex;
	cout << inorder[rootIndex] << ' '; // root �� ���

	getPreOrder(inStart, rootIndex - 1, postStart, postStart + leftSize - 1);
	getPreOrder(rootIndex + 1, inEnd, postStart + leftSize, postEnd - 1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	Input();
	getPreOrder(1, N, 1, N);

	return 0;
}