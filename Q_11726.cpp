/*
문제
2×n 크기의 직사각형을 1×2, 2×1 타일로 채우는 방법의 수를 구하는 프로그램을 작성하시오.

아래 그림은 2×5 크기의 직사각형을 채운 한 가지 방법의 예이다.



입력
첫째 줄에 n이 주어진다. (1 ≤ n ≤ 1,000)

출력
첫째 줄에 2×n 크기의 직사각형을 채우는 방법의 수를 10,007로 나눈 나머지를 출력한다.
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