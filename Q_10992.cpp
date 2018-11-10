#include <iostream>

using namespace std;

int main() {
	int N, line=0;
	scanf("%d", &N);

	while (line < N) {
		if (line == 0) {
			for (int j = 0; j < N - (line + 1); j++) printf(" ");
			printf("*\n");
		}
		else if (line == N - 1)
			for (int j = 0; j < 2*N - 1; j++) {
				printf("*");
			}
		else {
			for (int j = 0; j < N - (line + 1); j++) printf(" ");
			printf("*");
			for (int j = 0; j < 2 * line - 1; j++) printf(" ");
			printf("*\n");
		}
		line++;
	}
}