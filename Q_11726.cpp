/*
����
2��n ũ���� ���簢���� 1��2, 2��1 Ÿ�Ϸ� ä��� ����� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Ʒ� �׸��� 2��5 ũ���� ���簢���� ä�� �� ���� ����� ���̴�.



�Է�
ù° �ٿ� n�� �־�����. (1 �� n �� 1,000)

���
ù° �ٿ� 2��n ũ���� ���簢���� ä��� ����� ���� 10,007�� ���� �������� ����Ѵ�.
*/


//                         Top_Down
#include <stdio.h>

int D[1001];

int calculate(int n) {
	if (n == 1) {
		D[1] = 1;
	}
	if (n == 2) {
		D[2] = 2;
	}
	if (D[n] > 0) return D[n];

	D[n] = (calculate(n - 1) + calculate(n - 2)) % 10007;
	return D[n];
}

int main() {
	int n;
	scanf("%d", &n);
	printf("%d", calculate(n));
}

/*                         Bottom_UP
#include <cstdio>

int d[1001];

int main() {

	d[0] = 1;

	d[1] = 1;

	int n;

	scanf("%d", &n);

	for (int i = 2; i <= n; i++) {

		d[i] = d[i - 1] + d[i - 2];

		d[i] %= 10007;

	}

	printf("%d\n", d[n]);

	return 0;

}
*/