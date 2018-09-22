#include<stdio.h>

#define CRT_SECURE_NO_WARNINGS

int point[1000001];

int calculate(int n) {
	int temp = 0;

	if (n == 1) return 0;
	if (point[n] > 0) return point[n];

	point[n] = calculate(n - 1) + 1;

	if (n % 2 == 0) {
		temp = calculate(n / 2) + 1;
		if (temp < point[n])
			point[n] = temp;
	}

	if (n % 3 == 0) {
		temp = calculate(n / 3) + 1;
		if (temp < point[n])
			point[n] = temp;
	}
	return point[n];
}

int main() {
	int n;
	scanf("%d", &n);
	printf("%d", calculate(n));
}