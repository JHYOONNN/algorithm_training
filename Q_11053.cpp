/*
문제
수열 A가 주어졌을 때, 가장 긴 증가하는 부분 수열을 구하는 프로그램을 작성하시오.

예를 들어, 수열 A = {10, 20, 10, 30, 20, 50} 인 경우에 가장 긴 증가하는 부분 수열은 A = {10, 20, 10, 30, 20, 50} 이고, 길이는 4이다.

입력
첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000)이 주어진다.

둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (1 ≤ Ai ≤ 1,000)

출력
첫째 줄에 수열 A의 가장 긴 증가하는 부분 수열의 길이를 출력한다.
*/
#include <stdio.h>

int main() {
	int n;
	int A[1001], end=0;
	int D[1001];
	int temp=0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &A[i]);
	
	for (int i = 1; i <= n; i++) {
		D[i] = 1;
		for (int j = 1; j < i; j++) {
			if (A[j] < A[i]) temp = D[j] + 1;
			if (temp > D[i]) D[i] = temp;
			temp = 0;
		}
	}
	int ans = D[1];
	for (int i = 1; i <= n; i++) {
		if (ans < D[i]) ans = D[i];
	}
	printf("%d", ans);
}