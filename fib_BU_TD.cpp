// 피보나치 수열 BottomUp, TomDown 구현

#include<stdio.h>
#include<iostream>

int fibTDArray[100] = { 0, };
int fibBUArray[100] = { 0, };

int fib_TopDown(int n){
	if (n <= 1) {
		fibTDArray[n] = n;
	}

	else {
		if (fibTDArray[n] == 0) {
			fibTDArray[n] = fib_TopDown(n - 1) + fib_TopDown(n - 2);
			return fibTDArray[n];
		}

		else return fibTDArray[n];
	}
}

int fib_BottomUp(int n) {
	fibBUArray[0] = 0;
	fibBUArray[1] = 1;
	
	if (n <= 1) return fibBUArray[n];

	else {
		for (int i = 2; i <= n; i++) {
			fibBUArray[i] = fibBUArray[i - 1] + fibBUArray[i - 2];
		}
	}

	return fibBUArray[n];
}

int main() {
	int n = 7;

	fib_TopDown(n);
	fib_BottomUp(n);

	printf("피보나치 TopDown \n");
	for (int i = 0; i <= n; i++) {
		printf("%d\n", fibTDArray[i]);
	}

	printf("\n피보나치 BottomUp \n");
	for (int i = 0; i <= n; i++) {
		printf("%d\n", fibBUArray[i]);
	}
}