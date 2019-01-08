#include<iostream>

using namespace std;

long long A[1000000];
long long N, B, C;
long long dap = 0;

int main() {
	scanf("%lld", &N);
	for (int i = 0; i < N; i++)
		scanf("%lld", &A[i]);
	scanf("%lld %lld", &B, &C);

	for (int i = 0; i < N; i++) {
		A[i] -= B;
		dap++;
		if (A[i] > 0) {
			long long mok = A[i] / C;
			long long nam = A[i] % C;
			if (nam > 0) mok += 1;
			dap += mok;
		}
	}

	printf("%lld\n", dap);
}