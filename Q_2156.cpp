#include<stdio.h>

long long MAX(long long a,long long b,long long c) {
int max;
if (a > b) max = a; else max = b;
if (max < c) max = c;
return max;
}
int main() {
	long long n;
	long long P[10001];
	long long D[10001][2];
	long long dap;
	scanf("%lld", &n);

	for (int i = 1; i <= n; i++)
		scanf("%lld", &P[i]);

	D[1][0] = 0;
	D[1][1] = P[1];
	D[1][2] = P[1];

	for (int i = 2; i <= n; i++) {
		D[i][0] = MAX(D[i - 1][0], D[i - 1][1], D[i - 1][2]);
		D[i][1] = P[i] + D[i - 1][0];
		D[i][2] = P[i] + D[i - 1][1];
	}
	dap = MAX(D[n][0], D[n][1], D[n][2]);

	printf("%lld", dap);
	return 0;
}